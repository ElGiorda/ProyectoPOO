#include "Malo.h"
#include <SFML/System/Vector2.hpp>
#include <cmath>


using namespace std;
using namespace sf;

Malo::Malo(Vector2f pos, Vector2f dir) {
	m_t.loadFromFile("Meteor1.png");
	m_s.setTexture(m_t);
	m_s.setPosition(pos);
	m_s.setOrigin(25,25);
	m_s.setScale(1,1);	
	
	e_vel = dir*0.01f;
	
	vivo = true;
	
	hitbox();
}

void Malo::dibujar(RenderWindow &w){
	if (vivo){
		w.draw(m_s);
		//w.draw(m_hitbox);
	}
}

void Malo::actualizar(){
	if (vivo){
		m_s.move(e_vel);
		m_hitbox.setPosition(m_s.getPosition());
	}
}
Vector2f Malo::VerPos(){
	Vector2f pos1 = m_s.getPosition();
	return pos1;
}

bool Malo :: fuera_pantalla(){
	if (m_s.getPosition().x<0 or m_s.getPosition().x>940) return true;
	if (m_s.getPosition().y<0 or m_s.getPosition().y>540) return true;
	return false;
}

void Malo:: CambiarEstado(bool estado){
	this->vivo = estado;
}
bool Malo:: VerEstado(){
	return vivo;
}

void Malo :: hitbox(){
	
	bounds = m_s.getGlobalBounds();
	
	float diagonal = std::sqrt(bounds.width * bounds.width + bounds.height * bounds.height);
	float scale =15.f / diagonal;
	bounds.width *= scale;
	bounds.height *= scale;
	
	m_hitbox.setSize((sf::Vector2f(bounds.width, bounds.height)));
	m_hitbox.setPosition(bounds.left, bounds.top);

	m_hitbox.setOrigin(0,0);
	m_hitbox.setFillColor(sf::Color::Transparent);
	m_hitbox.setOutlineColor(sf::Color::Red);
	m_hitbox.setOutlineThickness(1.f);
}

FloatRect Malo::VerHitbox(){
	return m_hitbox.getGlobalBounds();;
}
