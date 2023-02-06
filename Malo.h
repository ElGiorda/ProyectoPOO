#ifndef MALO_H
#define MALO_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

using namespace sf;

class Malo {
public:
	
	Malo(Vector2f pos, Vector2f dir);
	void actualizar();
	void dibujar(RenderWindow &w);
	
	Vector2f VerPos();
	
	FloatRect VerHitbox();
	void hitbox();
	
	void CambiarEstado(bool);
	bool VerEstado();
	bool fuera_pantalla();
	
private:
	Texture m_t;
	Sprite m_s;
	
	Vector2f pos;
	Vector2f e_vel;
	
	RectangleShape m_hitbox;
	FloatRect bounds;
	
	bool vivo;
}; 

#endif
