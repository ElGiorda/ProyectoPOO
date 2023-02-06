#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Audio/Music.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/System/Time.hpp>

#include <vector>
#include <ctime>
#include <cmath>

#include "SceneManager.h"
#include "Balas_jugador.h"
#include "Malo.h"
#include "Jugador.h"
#include "Scene.h"
#include "Boost.h"

using namespace sf;

class Game : public Scene {
public:
	//Constructor 
	Game();
	//Eventos principales sobrecargados de clase Scene
	void update(SceneManager &sm) override;
	void draw(RenderWindow &w) override;
	void ProcessEvents(RenderWindow &w) override;
	//metodo para cargar todos los Textos
	void Textos();
	//metodos de control del juego
	bool control_Vida(); 
	void control_balas_jugador();
	void control_enemy();
	void control_generacion_enemy();
	void control_level();
	void control_puntaje();
	void control_boost();

	void mejora_puntaje();
	
	void e_dead(Balas_jugador& , int);
	
private:
	///fondo
	Texture Background_t;
	Sprite Background;
	///Textos
	Font font;
	Text healthText;
	Text levelText;
	Text enemy_deadText;
	Text puntajeText;
	///musica
	Music game_soundtrack;
	bool mute;
	
	bool back_menu;
	
	///vida
	Texture t_img_vida;
	Sprite s_img_vida;
	///Datos jugador 
	int playerHealth;
	Jugador j;
	vector <Balas_jugador> vec_bal_bueno;
	
	///Realcionado a enemy
	vector <Malo*> vec_enemy;
	Clock enemy_clock;
	float enemyGenerationInterval;
	float enemyGenerationTimer;
	int enemy_dead;
	int puntaje;
	int level = 1;
	///boost
	vector <Boost*> vec_boost;
	float prob_boost;
	int boost_type;
};

#endif

