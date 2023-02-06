#include "Game.h"


//Controla si las balas del jugador salen de la pantalla
bool fuera_de_la_pantalla(Balas_jugador &b){
	Vector2f p = b.VerPos();
	if (p.x<0 or p.x>940) return true;
	if (p.y<0 or p.y>540) return true;
	return false;
}
//Funcion para saber si tengo que borrar las balas del jugador o enemigos
bool borrar_balas_jugador(Balas_jugador &d){
	return !d.VerEstado();
}
bool enemigo_muerto(Malo* &m){
	return !m->VerEstado();
}
//Funcion que controla la colicion entre las balas del jugador y los enemigos
bool colisiona(Balas_jugador &b, Malo* &m) {
	
	sf::FloatRect b_bounds = b.VerHitbox();
	sf::FloatRect m_bounds = m->VerHitbox();
	
	if (b_bounds.intersects(m_bounds))return true ;
	return false;
}

//Funcion que controla la colicion entre el jugador y los enemigos 
bool colisionaJugador(Malo* &m, Jugador &j) {
	
	sf::FloatRect j_bounds = j.VerHitbox();
	sf::FloatRect m_bounds = m->VerHitbox();

	if (j_bounds.intersects(m_bounds)) return true ;
	return false;
}
//Funcion que controla si el jugador "agarra un boost"
bool colisionaBoost(Boost &b, Jugador &j) {
	
	sf::FloatRect j_bounds = j.VerHitbox();
	sf::FloatRect b_bounds = b.VerHitbox();
	
	if (j_bounds.intersects(b_bounds)) return true ;
	return false;
}
//inicializador
Game::Game() {
	//Inicializo las variables
	playerHealth = j.VerVida();
	puntaje=0;
	enemy_dead = 0;
	prob_boost = 0.0f;
	boost_type = -1;
	
	enemyGenerationInterval = 2.0f; // intervalo de generacion de enmigos 
	enemyGenerationTimer = 0.0f; //contador de tiempo, para saber si genera enemigos
	//Cargo la fuente
	font.loadFromFile("Minecraft.ttf");
	// inicia los textos necesarios en pantalla
	Textos();
	//Carga imagenes, de fondo y e la vida (bateria)
	Background_t.loadFromFile("fondo_nel.jpg");
	Background.setTexture(Background_t);
	Background.setPosition(Vector2f(0,0));
	
	t_img_vida.loadFromFile("bateriaf.png");
	s_img_vida.setTexture(t_img_vida);
	s_img_vida.setPosition(850,10);
	s_img_vida.scale(0.8,0.8);
	//Carga la musica y fija sus variables
	game_soundtrack.openFromFile("Juego.C.wav");
	game_soundtrack.play();
	game_soundtrack.setVolume(20);
	game_soundtrack.setLoop(true);
	mute=false;
	
	back_menu = false;
}
//Funcion para Cargar todos los textos que aparecen en pantalla
void Game :: Textos(){
/**	 Este texto fue reemplazado por la imagen de la bateria 
	healthText.setFont(font);
	healthText.setString("Vida: " + std::to_string(playerHealth));
	healthText.setCharacterSize(24);
	healthText.setFillColor(sf::Color::White);
	healthText.setPosition(10, 10);
*/
	levelText.setFont(font);
	levelText.setString("level: " + std::to_string(level));
	levelText.setCharacterSize(24);
	levelText.setFillColor(sf::Color::White);
	levelText.setPosition(10, 10);
	
	enemy_deadText.setFont(font);
	enemy_deadText.setString("Destruidos: " + std::to_string(enemy_dead));
	enemy_deadText.setCharacterSize(24);
	enemy_deadText.setFillColor(sf::Color::White);
	enemy_deadText.setPosition(120, 10);
	
	puntajeText.setFont(font);
	puntajeText.setString("Puntos: " + std::to_string(puntaje));
	puntajeText.setCharacterSize(24);
	puntajeText.setFillColor(sf::Color::White);
	puntajeText.setPosition(350, 10);
	
}
//Funcion para actualizar la escena
void Game::update(SceneManager& sm){
	
	///actualizacion del jugador
	j.actualizar();
	
	///actualizacion de balas del jugador
	for (Balas_jugador &x: vec_bal_bueno) x.actualizar();
	
	///actualizacion de enemigos 
	for (int i = 0; i<vec_enemy.size();++i) vec_enemy[i]->actualizar();
	
	///Se controla cada entrada a update la cantidad de vida, y las mismas se actualizan.
	if (control_Vida()) sm.Death(puntaje, enemy_dead);
	
	///En caso de apretar el scape, se vuelve al menu
	if (back_menu) sm.ChangeScene(SceneManager::s_menu);
	
	///Inicia todos los controladores de objetos que participan ene l juego
	control_balas_jugador();
	control_enemy();
	control_level();
	control_boost();
}
//Funcion que dibuja todo lo necesario en pantalla 
void Game::draw(RenderWindow& w){
	
	//w.clear(Color(0,0,0,255)); Esto no es necesario ya que hay un Background
	/// se dibujan todos los textos antes inciados
	w.draw(Background);
	w.draw(s_img_vida);
	w.draw(levelText);
	w.draw(enemy_deadText);
	w.draw(puntajeText);
	//w.draw(healthText); Fue reemplazado por una imagen 
	
	///se dibuja al jugador 
	j.dibujar(w);
	
	///Dibuja los boost que aparecen
	for (Boost* &b : vec_boost){
		b->dibujar(w);
	}
	///Dibuja las balas del jugador, y a los enemigos
	for (Balas_jugador &x: vec_bal_bueno) {x.dibujar(w);}
	for (Malo* &m : vec_enemy) {m->dibujar(w);}
	
	w.display();
}
/*procesa eventos, como cerrar la ventana con x, cambiar al menu con escape
	mutear la musica con la m*/
void Game::ProcessEvents(RenderWindow& w){	
	Event e;
	while(w.pollEvent(e)) {
		if(e.type == Event::Closed){
			game_soundtrack.stop();
			w.close();
		}
		if (e.type == Event::KeyReleased){
			if (e.key.code == Keyboard::M){
				mute = !mute;
				if(mute){
					game_soundtrack.setVolume(0);
				}else{
					game_soundtrack.setVolume(20);
				}
			}
			if (e.key.code == Keyboard::Escape){
				back_menu = true;
			}
		}
	}
}
//Controlador balas
void Game :: control_balas_jugador(){
	//Se generan los disparos del jugador
	if(j.debeDisparar()){vec_bal_bueno.push_back(j.GenerarDisparo());}
	
	//Elimina los disparos si colicionan con algun enemigo o si salen de la pantalla 
	auto it = remove_if(vec_bal_bueno.begin(),vec_bal_bueno.end(), borrar_balas_jugador);
	vec_bal_bueno.erase(it,vec_bal_bueno.end());
	
	auto it2 = remove_if(vec_bal_bueno.begin(),vec_bal_bueno.end(), fuera_de_la_pantalla);
	vec_bal_bueno.erase(it2,vec_bal_bueno.end());
}
//Controla si los enemigos mueren
void Game :: e_dead(Balas_jugador& b, int i ){
	///cambia el estado de la bala y del enemigo para poder borrar ambos*/
	b.CambiarEstado(false);
	vec_enemy[i]->CambiarEstado (false);
	///contador
	enemy_dead += 1;
	enemy_deadText.setString("Destruidos: " + std::to_string(enemy_dead));
}
//
void Game:: control_puntaje(){
	puntaje += (enemy_dead/level + level/5); //revisar (pero se puede dejar asi, por ahora)	
	puntajeText.setString("Puntos: " + std::to_string(puntaje));							
}
//Controla como y donde se generan los enemigos
void Game :: control_generacion_enemy(){
	
/**Controlador de tiempo, cuando llega al intervalo de generacion definido previamente
	genera el enemigo en la una posicion random dentro de la pantalla siempre a 250 pixeles
	alejado del personaje principal */
	
	Time elapsed = enemy_clock.restart();
	float dt = elapsed.asSeconds();	

	enemyGenerationTimer += dt;
	
	if(enemyGenerationTimer >= enemyGenerationInterval){ // s
		
		Vector2f pos;
		pos.x = rand()%(941);
		pos.y = rand()%(541);
		
		// Asegurar que el enemigo esté alejado del personaje principal
		while (sqrt(pow(pos.x - j.VerPos().x, 2) + pow(pos.y - j.VerPos().y, 2)) < 250) {
			pos.x = rand() % 940;
			pos.y = rand() % 540;
		}
		
		Vector2f dir = j.VerPos() - pos; // direccion en la que se mueve el enemigo
		Malo* x = new Malo(pos,dir); // crea un enemigo 
		vec_enemy.push_back(x);
		
		enemyGenerationTimer = 0.0f;
	}
}
//
void Game :: control_enemy(){
/// Controla si alguna de las balas del jugador coliciona con algun enemigo 
	for(Balas_jugador &b : vec_bal_bueno) {
		for (int i = 0; i<vec_enemy.size();++i){
			if (colisiona(b,vec_enemy[i])) {
				
				e_dead(b,i); 		// funcion de enemigos muerto s
				control_puntaje(); //funcion de puntaje 
				
				
				//Controla la probabilidad y el boost a generar
				prob_boost += 1 ;  																
				float chance = rand() % 100;												
				if (chance <= prob_boost){										
					Boost *b= new Boost (vec_enemy[i]->VerPos());				
					vec_boost.push_back(b);										
					prob_boost = 0;												
				}		 														
			}	
		}
	}
	
	control_generacion_enemy();
	
/**Cambia el estado en caso de que los enemigos salgan de la pantalla
	y luego de acuerdo al estado los elimina del vector*/
	for (int i=0; i < vec_enemy.size(); ++i){
		if (vec_enemy[i] -> fuera_pantalla()) {vec_enemy[i] -> CambiarEstado(false);}
	}
	auto itenemy = remove_if(vec_enemy.begin(),vec_enemy.end(), enemigo_muerto);
	vec_enemy.erase(itenemy,vec_enemy.end());
}
//
void Game :: control_boost(){
	for (auto itboost = vec_boost.begin(); itboost !=vec_boost.end();){
		Boost* &b = *itboost;
		boost_type = b->verBoost();;
		if (colisionaBoost(*b,j)){
			switch (boost_type) {
			case 0:
				if (playerHealth <4){
					j.cambiar_vida(1);
				}
				break;
			case 1:
				j.cambiar_mejora_disp(true);
				break;
			case 2:
				mejora_puntaje();
				break;
			}
			
			itboost = vec_boost.erase(itboost);
		}else{
			itboost++;
		}
	}
}
//
void Game :: mejora_puntaje(){
	puntaje += 100;
}
//
bool Game :: control_Vida(){
	//Ver si hay colicion de los enemigos con el jugador, en caso de que si, se pierde una vida
	for (int i = 0; i<vec_enemy.size();++i){
		if (colisionaJugador(vec_enemy[i],j)){
			if (j.PuedePerderVida()){
				j.cambiar_vida(0);
			}
		}
	}
	
	// actualizacion por si hay cambio en la vida
	playerHealth = j.VerVida();
	switch(playerHealth){
	case 4:
		t_img_vida.loadFromFile("bateriaf.png");
		break;
	case 3:
		t_img_vida.loadFromFile("bateria_uno.png");
		break;
	case 2:
		t_img_vida.loadFromFile("bateria2.png");
		break;
	case 1:
		t_img_vida.loadFromFile("bateria3.png");
		break;
	}
	
	healthText.setString("Vida: " + std::to_string(playerHealth));
	
	// en caso de quedarse sin vida, termina la partida
	if (j.VerVida() <= 0){
		return true;
	}
	return false;
}
//
void Game :: control_level(){
	if (enemy_dead == 10*level*1.5){
		level ++;
		enemyGenerationInterval *=0.80f;
		levelText.setString("level: " + std::to_string(level));
	}
}
