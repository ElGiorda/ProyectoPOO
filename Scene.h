#ifndef SCENE_H
#define SCENE_H
#include <SFML/Graphics/RenderWindow.hpp>
#include "SceneManager.h"

using namespace sf;
class SceneManager;

class Scene {
public:
	Scene();
	
	virtual void update(SceneManager& ) = 0;
	virtual void draw(RenderWindow &) = 0;
	virtual void ProcessEvents(RenderWindow&) =0;
	
	virtual ~Scene()=default;
private:
};

#endif

