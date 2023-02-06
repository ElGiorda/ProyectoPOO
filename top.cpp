#include "top.h"

top::top(vector <Score> V) {
	font.loadFromFile("gameplay.ttf");
	
	t_puntajes = V;
	t_next = false;
	
	Textos();
	
	t_Background_t.loadFromFile("top.jpg");
	Background.setTexture(t_Background_t);
	Background.setPosition(Vector2f(0,0));
	Background.scale(0.5,0.5);
	
}

void top::Textos(){
	
	for (int i=0;i<10;i++){
		string s;
		s += to_string(i+1);
		s.push_back('.');
		s.push_back(' ');
		
		for (int j =0; j<3;j++ ){
			s.push_back(t_puntajes[i].alias[j]);
		}
		s.push_back(' ');
		s.push_back(':');
		s.push_back(' ');
		s += to_string(t_puntajes[i].puntos);
		
		/**s.push_back(' ');
		s.push_back(' ');
		s.push_back(' ');
		s += "Asesinados: ";
		s += to_string(t_puntajes[i].enemy_killed);
		*/
		
		Text aux;
		aux.setCharacterSize(12);
		aux.setString(s);
		aux.setFont(font);
		aux.setFillColor(Color::Black);
		aux.setOutlineColor(Color::White);
		aux.setOutlineThickness(2);
		
		if (i<10) {
			aux.setPosition(400,172+(37*i));
		}
		T.push_back(aux);
	}
}


void top :: update(SceneManager &sm){
	if (t_next){
		sm.ChangeScene(SceneManager::s_menu);
	}
}
void top::draw(RenderWindow& w){
	//w.clear(Color(0,0,0,255));
	w.draw(Background);

	for (int i=0; i<10; i++){
		w.draw(T[i]);
	}
	
	w.display();
}
void top::ProcessEvents(RenderWindow &w){
	Event event;
	while(w.pollEvent(event)) {
		if(event.type == Event::Closed)
			w.close();	
		if (event.type == Event::KeyPressed){
			if(event.key.code == Keyboard::Return)
				t_next = true;
			if(event.key.code == Keyboard::Escape)
				t_next = true;
		}
	}
}

