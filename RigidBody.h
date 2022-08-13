#pragma once
#include "Vector2D.h"
#include <SFML/Graphics.hpp>

class RigidBody
{
public:
	RigidBody();
	RigidBody(float width, float height, float mass, float gravity, float drag, float accelerationForce);
	~RigidBody();

	void AddForce(const Vector2D& vector);
	void CalculateAcceleration();
	void CalculateVelocity();
	void CalculatePosition();
	void Drag();
	void CheckWindowBounds(const sf::RenderTarget* target);
	bool CheckCollision(const RigidBody& rb);

	void UpdatePhysics();
	Vector2D position;

	Vector2D forces;
	Vector2D velocity;
	Vector2D acceleration;
	float width, height, mass, gravity, drag, accelerationForce;
};

