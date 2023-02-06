#include "MainMenu.h"
#include <SFML/Window/Event.hpp>
#include "SceneManager.h"

MainMenu::MainMenu() {
	font.loadFromFile("digital-7.ttf");
	selectedItemIndex = 0;
	
	m_iniciar = false;
	m_scores = false;
	
	menu_soundtrack.openFromFile("Menu.wav");
	menu_soundtrack.play();
	menu_soundtrack.setVolume(20);
	menu_soundtrack.setLoop(true);
	
	menu[0].setFont(font);
	menu[0].setCharacterSize(25);
	menu[0].setString("Nueva Partida");
	menu[0].setFillColor(sf::Color::Green);
	menu[0].setPosition(sf::Vector2f(170, 200));
	menu[0].setOutlineColor(sf::Color::Blue);
	menu[0].setOutlineThickness(1.f);
		
	menu[1].setFont(font);
	menu[1].setCharacterSize(25);
	menu[1].setString("Puntuaciones");
	menu[1].setFillColor(sf::Color::White);
	menu[1].setPosition(sf::Vector2f(170, 240));
	menu[0].setOutlineColor(sf::Color::Blue);
	menu[0].setOutlineThickness(1.f);
	
	menu[2].setFont(font);
	menu[2].setCharacterSize(25);
	menu[2].setString("Salir");
	menu[2].setFillColor(sf::Color::White);
	menu[2].setPosition(sf::Vector2f(170, 280));
	menu[0].setOutlineColor(sf::Color::Blue);
	menu[0].setOutlineThickness(1.f);
	
	m_Background_t.loadFromFile("menu.jpg");
	m_Background.setTexture(m_Background_t);
	m_Background.setPosition(Vector2f(0,0));
	m_Background.scale(0.5,0.5);
	
}
void MainMenu::update(SceneManager &sm){
	if (m_iniciar){
		sm.ChangeScene(SceneManager::s_game);
	}
	if (m_scores){
		sm.ChangeScene(SceneManager::s_top);
	}
}
void MainMenu::draw(RenderWindow& w){
	w.clear(Color(0,0,0,255));
	w.draw(m_Background);
	for (int i = 0; i < 3; i++)
	{
		w.draw(menu[i]);
	}
	
	w.display();
}
void MainMenu::ProcessEvents(RenderWindow &window){
	Event event;
	while (window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::KeyPressed:
			switch (event.key.code)
		{
		case sf::Keyboard::Up:
			if (selectedItemIndex - 1 >= 0)
		{
				menu[selectedItemIndex].setFillColor(sf::Color::White);
				selectedItemIndex--;
				menu[selectedItemIndex].setFillColor(sf::Color::Green);
		}
			break;
			
		case sf::Keyboard::Down:
			if (selectedItemIndex + 1 < 3)
		{
				menu[selectedItemIndex].setFillColor(sf::Color::White);
				selectedItemIndex++;
				menu[selectedItemIndex].setFillColor(sf::Color::Green);
		}
			break;
		case sf::Keyboard::M:
			mute = !mute;
			if (mute)
				menu_soundtrack.setVolume(0);
			else
				menu_soundtrack.setVolume(20);
			break;
		case sf::Keyboard::Return:
			switch (selectedItemIndex)
		{
		case 0:
			
			m_iniciar=true;
			
			break;
		case 1:
			m_scores = true;
			break;
		case 2:
			window.close();
			break;
		}
			break;
		}
			break;
		case sf::Event::Closed:
			menu_soundtrack.stop();
			window.close();
		break;
		}
	}
}
