#include "SceneManager.h"
#include "MainMenu.h"
#include "top.h"
#include "Gameover.h"
#include "Game.h"


SceneManager::SceneManager() : m_win(VideoMode(940,540),"Ejemplo de SFML") {
	m_win.setFramerateLimit(60);
	//inicializa con el menu y la siguiente escena vacia, para poder usarla
	m_Sce = new MainMenu;
	next_Sce = nullptr;
	
}
void SceneManager::Iniciar(){
	while(m_win.isOpen()){
		if (next_Sce){ // si el punto no es nulo, comienza el if 
			delete m_Sce; // borra escena actuali
			m_Sce = next_Sce; // cambia la siguiente a la actual
			next_Sce = nullptr; // borra la siguiente para poder usarla y que no entre al if
		}
		//Realiza los eventos importantes
		m_Sce -> ProcessEvents(m_win);
		m_Sce -> update(*this); //Este trabaja sobre la escena, los otros en la ventana
		m_Sce -> draw(m_win);
		
	}
}
/** Tando death como ChangeScene controlan la escena siguiente 
Death esta apart porque pude la cantidad de enemigos y el puntaje 
porque la escena de Gameover traba con el puntaje y los enemigos
*/ 
void SceneManager :: Death(int punt, int enemy_k){
	// realiza  pasos similares a Iniciar
	if (next_Sce){
		delete next_Sce;
		next_Sce = nullptr;
	}
	next_Sce = new Gameover(punt, enemy_k);
}
// elije la escene siguiente de acuerdo a lo que se le pida
void SceneManager::ChangeScene(Escena escena){
	if(escena == SceneManager::s_menu){
		next_Sce = new MainMenu();}
	else if(escena == SceneManager::s_game){
		next_Sce = new Game();}
	else if(escena == SceneManager::s_top){
		next_Sce = new top(sm_highscores.return_scores());}
}

void SceneManager::NewScore(Score aux) {
	sm_highscores.Insert_Score(aux);
}

/**Destructor para eliminar los punteros generados con new y guardar la informacion 
de los score en el archivo*/
SceneManager::~SceneManager(){
	sm_highscores.SaveHighscore();
	delete next_Sce;
	delete m_Sce;
}
