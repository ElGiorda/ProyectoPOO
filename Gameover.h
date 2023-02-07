#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "Scene.h"
#include "Scores.h"
#include "SceneManager.h"


class Gameover : public Scene{
public:
	Gameover(int,int);
	
	void update(SceneManager&) override;
	void ProcessEvents(RenderWindow&)override;
	void draw(RenderWindow&)override;
	
private:
	Font g_font;
	
	Clock g_clock;
	
	Text T_a;
	Text T_b;
	Text T_c;
	
	char a,b,c;
	
	int g_puntos;
	int g_enemy_k;
	
	bool g_next;
	
	Texture m_Background_t;
	Sprite m_Background;
};

#endif

