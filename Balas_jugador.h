#ifndef BALAS_JUGADOR_H
#define BALAS_JUGADOR_H

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

using namespace sf;

class Balas_jugador {
public:
	
	Balas_jugador(Vector2f pos, Vector2f dir);
	
	void actualizar();
	void dibujar(RenderWindow &w);
	Vector2f VerPos();
	
	void CambiarEstado (bool);
	bool VerEstado();
	
	void hitbox();
	FloatRect VerHitbox();
private:
	CircleShape j_circ;
	Vector2f j_vel;
	
	bool m_estado;
	
	RectangleShape bj_hitbox;
	FloatRect bounds;
};

#endif

