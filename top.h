#ifndef TOP_H
#define TOP_H

#include <vector>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "Scene.h"
#include "Scores.h"
#include "SceneManager.h"

using namespace std;

class top : public Scene {
public:
	top(vector <Score>);
	
	void Textos();
	
	void update(SceneManager&) override;
	void ProcessEvents(RenderWindow&) override;
	void draw(RenderWindow&) override;
	
private:
	Font font;
	
	vector <Text> T;
	
	bool t_next;
	
	vector <Score> t_puntajes;
	
	Texture t_Background_t;
	Sprite Background;
};

#endif

