#ifndef JUGADOR_H
#define	JUGADOR_H

#include <SFML/System/Clock.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

#include "Balas_jugador.h"

class Jugador {
public:
	
	Jugador();
	
	void actualizar();
	void dibujar(RenderWindow &w);
	
	Vector2f VerPos();

	void cambiar_mejora_disp (bool);
	Balas_jugador GenerarDisparo();
	bool debeDisparar();
	
	FloatRect VerHitbox();
	void hitbox();
	void recibio_hit();
	bool PuedePerderVida();
	void cambiar_vida(int);
	int VerVida();
	
	void cambiar_textura(int);
	
	void limites_pantalla();
	
private:
	Texture m_t;
	Sprite m_s;
	
	Vector2f pos;
	
	Clock m_shoot_clock;
	Clock m_life_clock;
	Clock m_clock;
	
	int vida;
	
	RectangleShape j_hitbox;
	
	float v_atk;

	bool impactado;
	int increment;
}; 

#endif

