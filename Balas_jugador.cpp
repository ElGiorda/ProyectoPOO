#include "Balas_jugador.h"

Balas_jugador::Balas_jugador(Vector2f pos, Vector2f dir) {
	j_circ.setPosition(pos);
	j_circ.setRadius(5);
	j_circ.setFillColor({Color::Red});
	j_circ.setOutlineColor({Color::Black});
	j_circ.setOutlineThickness(1);
	j_vel = dir*5.f;
	
	m_estado = true;
	
	hitbox();
}
Vector2f Balas_jugador::VerPos(){
	return j_circ.getPosition();
}

void Balas_jugador::actualizar(){
	j_circ.move(j_vel);
	bj_hitbox.setPosition(j_circ.getPosition());
}

void Balas_jugador::dibujar(RenderWindow &w){
	if(m_estado == true){
		w.draw(j_circ);
		//w.draw(bj_hitbox);
	}
}
void Balas_jugador :: CambiarEstado(bool estado){
	this->m_estado = estado;
}
bool Balas_jugador:: VerEstado(){
	return m_estado;
}
void Balas_jugador:: hitbox(){
	
	bounds = j_circ.getGlobalBounds();
	
	bj_hitbox.setSize((Vector2f(bounds.width, bounds.height)));
	bj_hitbox.setPosition(bounds.left, bounds.top);
	
	bj_hitbox.setOrigin(0,0);
	bj_hitbox.setFillColor(sf::Color::Transparent);
	bj_hitbox.setOutlineColor(sf::Color::Red);
	bj_hitbox.setOutlineThickness(1.f);
}

FloatRect Balas_jugador::VerHitbox(){
	return bj_hitbox.getGlobalBounds();;
}
