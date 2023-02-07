#include "Gameover.h"

Gameover::Gameover(int p, int ek) {
	
	g_font.loadFromFile("gameplay.ttf"); //cambiar
	
	g_next = false;
	
	a=b=c='-';
	g_puntos = p;
	g_enemy_k = ek;
	
	T_a.setString(a);
	T_a.setFont(g_font);
	T_a.setFillColor(Color::Black);
	T_a.setOutlineColor(Color::White);
	T_a.setOutlineThickness(2);
	T_a.setPosition(430,350);
	
	T_b.setString(b);
	T_b.setFont(g_font);
	T_b.setFillColor(Color::Black);
	T_b.setOutlineColor(Color::White);
	T_b.setOutlineThickness(2);
	T_b.setPosition(455,350);
	
	T_c.setString(c);
	T_c.setFont(g_font);
	T_c.setFillColor(Color::Black);
	T_c.setOutlineColor(Color::White);
	T_c.setOutlineThickness(2);
	T_c.setPosition(480,350);
	
	m_Background_t.loadFromFile("gameoover.jpg");
	m_Background.setTexture(m_Background_t);
	m_Background.setPosition(Vector2f(0,0));
	m_Background.scale(0.5,0.5);
	
}
//
void Gameover :: update(SceneManager &sm){
	
	T_a.setString(a);
	T_b.setString(b);
	T_c.setString(c);
	
	if (g_next){
		Score aux;
		aux.alias[0]=a;
		aux.alias[1]=b;
		aux.alias[2]=c;
		aux.puntos = g_puntos;
		aux.enemy_killed = g_enemy_k;
		
		sm.NewScore(aux);
		
		sm.ChangeScene(SceneManager::s_top);
	}
}
//
void Gameover::draw(RenderWindow& w){
	//w.clear(Color(0,0,0,255));
	w.draw(m_Background);
	
	int seconds = g_clock.getElapsedTime().asSeconds()*3;
	
	if (seconds%3 == 1){
		w.draw(T_a);
		w.draw(T_b);
		w.draw(T_c);
	}
	if (seconds%3 == 2) g_clock.restart();
	
	w.display();
}
void Gameover :: ProcessEvents(RenderWindow &w){
Event e;

while(w.pollEvent(e)) {
	if(e.type == Event::Closed)
		w.close();
	if(e.type == Event::KeyPressed){
		if(e.key.code == Keyboard::Escape)
			w.close();
		/**if(e.key.code == Keyboard::Space)
			g_next = true;*/
		if(e.key.code == Keyboard::Return)
			g_next = true;
	}
		if(e.type == Event::KeyReleased){
			if(e.key.code == Keyboard::A){
				if(a=='-'){a='A';}
				else if(b=='-'){b='A';}
				else if(c=='-'){c='A';}
			}
			else if(e.key.code == Keyboard::B){
				
				if(a=='-'){a='B';}
				else if(b=='-'){b='B';}
				else if(c=='-'){c='B';}
			}
			else if(e.key.code == Keyboard::C){
				
				if(a=='-'){a='C';}
				else if(b=='-'){b='C';}
				else if(c=='-'){c='C';}
			}
			else if(e.key.code == Keyboard::D){
				
				if(a=='-'){a='D';}
				else if(b=='-'){b='D';}
				else if(c=='-'){c='D';}
			}
			else if(e.key.code == Keyboard::E){
				
				if(a=='-'){a='E';}
				else if(b=='-'){b='E';}
				else if(c=='-'){c='E';}
			}
			else if(e.key.code == Keyboard::F){
				
				if(a=='-'){a='F';}
				else if(b=='-'){b='F';}
				else if(c=='-'){c='F';}
			}
			else if(e.key.code == Keyboard::G){
				
				if(a=='-'){a='G';}
				else if(b=='-'){b='G';}
				else if(c=='-'){c='G';}
			}
			else if(e.key.code == Keyboard::H){
				
				if(a=='-'){a='H';}
				else if(b=='-'){b='H';}
				else if(c=='-'){c='H';}
			}
			else if(e.key.code == Keyboard::I){
				
				if(a=='-'){a='I';}
				else if(b=='-'){b='I';}
				else if(c=='-'){c='I';}
			}
			else if(e.key.code == Keyboard::J){
				
				if(a=='-'){a='J';}
				else if(b=='-'){b='J';}
				else if(c=='-'){c='J';}
			}
			else if(e.key.code == Keyboard::K){
				
				if(a=='-'){a='K';}
				else if(b=='-'){b='K';}
				else if(c=='-'){c='K';}
			}
			else if(e.key.code == Keyboard::L){
				
				if(a=='-'){a='L';}
				else if(b=='-'){b='L';}
				else if(c=='-'){c='L';}
			}
			else if(e.key.code == Keyboard::M){
				
				if(a=='-'){a='M';}
				else if(b=='-'){b='M';}
				else if(c=='-'){c='M';}
			}
			else if(e.key.code == Keyboard::N){
				
				if(a=='-'){a='N';}
				else if(b=='-'){b='N';}
				else if(c=='-'){c='N';}
			}
			else if(e.key.code == Keyboard::O){
				
				if(a=='-'){a='O';}
				else if(b=='-'){b='O';}
				else if(c=='-'){c='O';}
			}
			else if(e.key.code == Keyboard::P){
				
				if(a=='-'){a='P';}
				else if(b=='-'){b='P';}
				else if(c=='-'){c='P';}
			}
			else if(e.key.code == Keyboard::Q){
				
				if(a=='-'){a='Q';}
				else if(b=='-'){b='Q';}
				else if(c=='-'){c='Q';}
			}
			else if(e.key.code == Keyboard::R){
				
				if(a=='-'){a='R';}
				else if(b=='-'){b='R';}
				else if(c=='-'){c='R';}
			}
			else if(e.key.code == Keyboard::S){
				
				if(a=='-'){a='S';}
				else if(b=='-'){b='S';}
				else if(c=='-'){c='S';}
			}
			else if(e.key.code == Keyboard::T){
				
				if(a=='-'){a='T';}
				else if(b=='-'){b='T';}
				else if(c=='-'){c='T';}
			}
			else if(e.key.code == Keyboard::U){
				
				if(a=='-'){a='U';}
				else if(b=='-'){b='U';}
				else if(c=='-'){c='U';}
			}
			else if(e.key.code == Keyboard::V){
				
				if(a=='-'){a='V';}
				else if(b=='-'){b='V';}
				else if(c=='-'){c='V';}
			}
			else if(e.key.code == Keyboard::W){
				
				if(a=='-'){a='W';}
				else if(b=='-'){b='W';}
				else if(c=='-'){c='W';}
			}
			else if(e.key.code == Keyboard::X){
				
				if(a=='-'){a='X';}
				else if(b=='-'){b='X';}
				else if(c=='-'){c='X';}
			}
			else if(e.key.code == Keyboard::Y){
				
				if(a=='-'){a='Y';}
				else if(b=='-'){b='Y';}
				else if(c=='-'){c='Y';}
			}
			else if(e.key.code == Keyboard::Z){
				
				if(a=='-'){a='Z';}
				else if(b=='-'){b='Z';}
				else if(c=='-'){c='Z';}
			}
		
	}
	
}
}



