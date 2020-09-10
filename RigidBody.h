#pragma once
#include "Vector2D.h"
#include "SDL.h"

#define UNIT_MASS 1		//kg
#define GRAVITATION 9.8		//m/s^2

class RigidBody {
public:
	RigidBody() {
		m_mass = UNIT_MASS;
		m_gravitation = GRAVITATION;
	}

	//Setters
	inline void setMass(float m) { this->m_mass = m; }
	inline void setGravitation(float g) { this->m_gravitation = g; }

	//Force
	void applyForce(Vector2D f) { this->m_force = f; }
	void applyForceX(float f_x) { this->m_force.x = f_x; }
	void applyForceY(float f_y) { this->m_force.y = f_y; }
	void clearForce() { this->m_force = Vector2D(0, 0); }

	//Friction
	void applyFriction(Vector2D fs) { m_friction = fs; }
	void clearFriction() { m_friction = Vector2D(0, 0); }

	//Update
	void update(float dt) {
		m_acceleration.x = (m_force.x - m_friction.x) / m_mass;
		m_acceleration.y = m_gravitation + m_force.y / m_mass;
		m_velocity = m_acceleration * dt;
		m_position = m_velocity * dt;
	}

public:
	float m_mass;
	float m_gravitation;
	Vector2D m_force;
	Vector2D m_friction;
	Vector2D m_position;
	Vector2D m_velocity;
	Vector2D m_acceleration;


};