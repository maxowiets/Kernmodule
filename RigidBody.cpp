#include "RigidBody.h"

RigidBody::RigidBody()
{
	this->width = 10;
	this->height = 10;
	this->mass = 1;
	this->gravity = 0;
	this->drag = .1;
	this->accelerationForce = 1;
}

RigidBody::RigidBody(float width, float height, float mass, float gravity, float drag, float accelerationForce)
{
	this->width = width;
	this->height = height;
	this->mass = mass;
	this->gravity = gravity;
	this->drag = drag;
	this->accelerationForce = accelerationForce;
}

RigidBody::~RigidBody()
{

}

void RigidBody::AddForce(const Vector2D& vector)
{
	forces = vector * accelerationForce / mass;
}

void RigidBody::CalculateAcceleration()
{
	this->acceleration = forces;
	this->acceleration.y += gravity;
}

void RigidBody::CalculateVelocity()
{
	this->velocity += this->acceleration;
	Drag();
}

void RigidBody::CalculatePosition()
{
	this->position += this->velocity;
}

void RigidBody::Drag()
{
	this->velocity *= 1.f - this->drag;
}

void RigidBody::CheckWindowBounds(const sf::RenderTarget* target)
{
	if (this->position.x < 0)
	{
		this->position.x = 0;
		this->velocity.x *= -1;
		this->acceleration = 0;
	}
	else if (this->position.x + this->width > target->getSize().x)
	{
		this->position.x = target->getSize().x - this->width;
		this->velocity.x *= -1;
		this->acceleration = 0;
	}
}

bool RigidBody::CheckCollision(const RigidBody& rb)
{
	return false;
}

void RigidBody::UpdatePhysics()
{
	CalculateAcceleration();
	CalculateVelocity();
	Drag();
	CalculatePosition();
}