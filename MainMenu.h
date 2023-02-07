#ifndef MAINMENU_H
#define MAINMENU_H
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include "Scene.h"
#include <SFML/Audio/Music.hpp>
#include <SFML/Graphics/Sprite.hpp>

using namespace sf;

class MainMenu : public Scene{
public:
	MainMenu();
	
	void update(SceneManager &) override;
	void draw(RenderWindow& w) override;
	void ProcessEvents(RenderWindow& w) override;
private:
	int selectedItemIndex;
	Font font;
	Text menu[3];
	
	
	Music menu_soundtrack;
	bool mute;
	
	bool m_iniciar;
	bool m_scores;
	
	Texture m_Background_t;
	Sprite m_Background;
	
};

#endif

