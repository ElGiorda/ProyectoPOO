#include "Jugador.h"

Jugador::Jugador() {
	///inicializo variables importantes
	m_t.loadFromFile("nave_up.png");
	m_s.setTexture(m_t);
	m_s.setPosition(470,260);
	m_s.setScale(1,1);
	m_s.setOrigin(20,20);
	
	vida = 4;
	v_atk = 500;
	
	hitbox();
	
	impactado = false;
	m_clock.restart();
	
	increment = 25; 
}
//actualizacion del jugador
void Jugador::actualizar(){
	///parpadeo al ser impactado
	if(impactado){
		Color color = m_s.getColor();
		if(color.a >= 255 || color.a <= 0) increment *= -1;{
			m_s.setColor(Color(255, 255, 255, color.a+increment));
			if(m_life_clock.getElapsedTime().asSeconds() >= 1.5){
				impactado = false;
				m_s.setColor(Color(255, 255, 255, 255));
			}
		}
	}
	
	if(Keyboard::isKeyPressed(Keyboard::D)){ //derecha
		m_s.move(2,0);
		if (!Keyboard::isKeyPressed(Keyboard::Up) and !Keyboard::isKeyPressed(Keyboard::Down) and !Keyboard::isKeyPressed(Keyboard::Left))
		cambiar_textura(0);
	}
	if(Keyboard::isKeyPressed(Keyboard::A)){
		m_s.move(-2,0);
		if (!Keyboard::isKeyPressed(Keyboard::Up) and !Keyboard::isKeyPressed(Keyboard::Right) and !Keyboard::isKeyPressed(Keyboard::Down))
		cambiar_textura(1);
	}
	if(Keyboard::isKeyPressed(Keyboard::W)){
		m_s.move(0,-2);
		if (!Keyboard::isKeyPressed(Keyboard::Down) and !Keyboard::isKeyPressed(Keyboard::Right) and !Keyboard::isKeyPressed(Keyboard::Left))
		cambiar_textura(2);
	}
	if(Keyboard::isKeyPressed(Keyboard::S)){
		m_s.move(0,2);
		if (!Keyboard::isKeyPressed(Keyboard::Up) and !Keyboard::isKeyPressed(Keyboard::Right) and !Keyboard::isKeyPressed(Keyboard::Left))
		cambiar_textura(3);
	}
	
	j_hitbox.setPosition(m_s.getPosition());
	limites_pantalla();	
}
//
void Jugador::dibujar(RenderWindow &w){
	w.draw(m_s);
	//w.draw(j_hitbox); 
}
//
Vector2f Jugador::VerPos(){
	Vector2f pos1 = m_s.getPosition();
	return pos1;
}
//
bool Jugador::debeDisparar(){
	if(m_shoot_clock.getElapsedTime().asMilliseconds()<v_atk)return false;
	
	if(not Keyboard::isKeyPressed(Keyboard::Right) && 
	   not Keyboard::isKeyPressed(Keyboard::Left) &&
	   not Keyboard::isKeyPressed(Keyboard::Up) &&
	   not Keyboard::isKeyPressed(Keyboard::Down)) return false;
	
	if (Keyboard::isKeyPressed(Keyboard::Right) && 
		Keyboard::isKeyPressed(Keyboard::Left) || 
		Keyboard::isKeyPressed(Keyboard::Right) && 
		Keyboard::isKeyPressed(Keyboard::Down)|| 
		Keyboard::isKeyPressed(Keyboard::Right) && 
		Keyboard::isKeyPressed(Keyboard::Up))return false;
	
	if (Keyboard::isKeyPressed(Keyboard::Left) && 
		Keyboard::isKeyPressed(Keyboard::Up) || 
		Keyboard::isKeyPressed(Keyboard::Left) && 
		Keyboard::isKeyPressed(Keyboard::Down))return false;
	
	if (Keyboard::isKeyPressed(Keyboard::Down) && 
		Keyboard::isKeyPressed(Keyboard::Up))return false;
	
	m_shoot_clock.restart();
	return true;
}
//
Balas_jugador Jugador::GenerarDisparo(){
	Vector2f p = m_s.getPosition();
	Vector2f d;
	if(Keyboard::isKeyPressed(Keyboard::Right)){ //derecha
		d.x=1;
		d.y=0;
		cambiar_textura(0);
		p.x = p.x + 20;
		p.y = p.y - 2;
		
	}
	if(Keyboard::isKeyPressed(Keyboard::Left)){
		d.x=-1;
		d.y=0;
		cambiar_textura(1);
		p.x = p.x - 20;
		p.y = p.y - 2;
	}
	if(Keyboard::isKeyPressed(Keyboard::Up)){
		d.x=0;
		d.y=-1;
		cambiar_textura(2);
		p.x = p.x - 2 ;
		p.y = p.y - 20;
	}
	if(Keyboard::isKeyPressed(Keyboard::Down)){
		d.x=0;
		d.y=1;
		cambiar_textura(3);
		p.x = p.x - 2  ;
		p.y = p.y + 20 ;
	}
	
	return Balas_jugador(p,d);
}
//
void Jugador::cambiar_textura(int x) {
	if (x==0){
		m_t.loadFromFile ("nave_right.png");
	}
	if (x==1){
		m_t.loadFromFile ("nave_left.png");
	}
	if (x==2){
		m_t.loadFromFile ("nave_up.png");
	}
	if (x==3){
		m_t.loadFromFile ("nave_down.png");
	}
}
//
bool Jugador::PuedePerderVida (){
	if(m_life_clock.getElapsedTime().asMilliseconds()<1500){
		impactado = true;
		return false;
	}
	m_life_clock.restart();
	return true;
}
//
void Jugador :: cambiar_vida(int x){
	if (x == 0) vida--;
	else if (x == 1 ) vida ++;
}
//
int Jugador :: VerVida(){
	return vida;
}
//
void Jugador :: hitbox(){
	j_hitbox.setSize(Vector2f(38,40));
	j_hitbox.setOrigin(20,20);
	j_hitbox.setFillColor(sf::Color::Transparent);
	j_hitbox.setOutlineColor(sf::Color::Red);
	j_hitbox.setOutlineThickness(1.f);
}
//
FloatRect Jugador :: VerHitbox(){
	return j_hitbox.getGlobalBounds();
}
//
void Jugador :: limites_pantalla(){
	if (m_s.getPosition().x < 20)
		m_s.setPosition(20, m_s.getPosition().y);
	if (m_s.getPosition().x + m_s.getGlobalBounds().width > 960)
		m_s.setPosition(960 - m_s.getGlobalBounds().width, m_s.getPosition().y);
	if (m_s.getPosition().y < 20)
		m_s.setPosition(m_s.getPosition().x, 20);
	if (m_s.getPosition().y + m_s.getGlobalBounds().height > 560)
		m_s.setPosition(m_s.getPosition().x, 560 - m_s.getGlobalBounds().height);
}
//
void Jugador :: cambiar_mejora_disp (bool x){
	if(x){
		if (v_atk >= 80){
			v_atk *= 0.85;
		}
	}
}
