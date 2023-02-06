#include "Boost.h"

Boost::Boost(Vector2f pos) {
	b_circ.setPosition(pos);
	b_circ.setRadius(6);
	b_circ.setFillColor({0,200,0});
	
	m_tipo = rand() % 3;
	
	switch(m_tipo){
	case 0:
		m_texture.loadFromFile("suma_bateria.png");
		m_sprite.scale(0.3,0.3);
		break;
	case 1:
		m_texture.loadFromFile("nave_right.png");
		break;
	case 2:
		m_texture.loadFromFile("moneda.png");
		m_sprite.scale(0.09,0.09);
		break;
	}
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(pos);
	
	hitbox();
}
FloatRect Boost :: VerHitbox(){
	return b_circ.getGlobalBounds();
}
void Boost :: dibujar(RenderWindow &w){
	
	w.draw (m_sprite);
	//w.draw(b_circ);
	//w.draw (m_hitbox);
}

int Boost :: verBoost(){
	return m_tipo;
}
void Boost :: hitbox(){
	
	bounds = b_circ.getGlobalBounds();
	
	m_hitbox.setSize((sf::Vector2f(bounds.width, bounds.height)));
	m_hitbox.setPosition(bounds.left, bounds.top);
	
	m_hitbox.setOrigin(0,0);
	m_hitbox.setFillColor(sf::Color::Transparent);
	m_hitbox.setOutlineColor(sf::Color::Red);
	m_hitbox.setOutlineThickness(1.f);
	
}
