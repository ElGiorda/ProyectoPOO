#ifndef BOOST_H
#define BOOST_H

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

using namespace sf;

class Boost {
public:

	Boost(Vector2f);
	
	void dibujar(RenderWindow &);
	
	int verBoost();
	
	FloatRect VerHitbox();
	void hitbox();
	
private:
	CircleShape b_circ;
	RectangleShape m_hitbox;
	FloatRect bounds;
	
	int m_tipo;
	
	Texture m_texture;
	Sprite m_sprite;
};

#endif

