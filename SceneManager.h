#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H
#include "Scene.h"
#include <SFML/Graphics/RenderWindow.hpp>

#include <vector>
#include "Scores.h"
using namespace std;
using namespace sf;
class Scene;
class HighScores;

class SceneManager {
public:
	
	enum Escena{ s_menu, s_game, s_top, s_gameover};
	
	SceneManager();
	
	void Iniciar();
	void Death(int, int);
	void ChangeScene(Escena);
	
	void Update();
	void ProcessEvents();
	void Draw();
	
	void NewScore(Score);
	
	~SceneManager();
private:
	
	RenderWindow m_win;
	
	Scene* m_Sce;
	Scene* next_Sce;
	
	Scores sm_highscores;
};

#endif

