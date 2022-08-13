#include "Enemy.h"

Enemy::Enemy() : RigidBody()
{
	this->shape.setPosition(100, 100);
	this->enemySprite.setPosition(100, 100);
	this->width = 10;
	this->height = 10;
	this->radiusSize = 10;
	this->initVariables(100, 100);
	this->initShape();
}

Enemy::Enemy(float radiusSize) : RigidBody()
{
	this->radiusSize = radiusSize;
	this->initVariables(100, 100);
	this->initShape();
}

Enemy::Enemy(float startX, float startY, float radiusSize, sf::Texture* enemyTexture, float mass, float gravity, float drag, float accelerationForce) : RigidBody(width, height, mass, gravity, drag, accelerationForce)
{
	this->shape.setPosition(startX, startY);
	this->enemySprite.setPosition(startX, startY);
	this->enemySprite.setTexture(*enemyTexture);
	this->radiusSize = radiusSize;
	this->width = radiusSize * 2;
	this->height = radiusSize * 2;
	this->initVariables(startX, startY);
	this->initShape();
}

Enemy::~Enemy()
{

}

void Enemy::updatePosition()
{
	this->shape.setPosition(this->position.x, this->position.y);
	this->enemySprite.setPosition(this->position.x, this->position.y);
}


void Enemy::update(const sf::RenderTarget* target)
{
	this->UpdatePhysics();
	this->CheckWindowBounds(target);
	this->updatePosition();
}

void Enemy::render(sf::RenderTarget* target)
{
	//target->draw(this->shape);
	target->draw(this->enemySprite);
}

void Enemy::initShape()
{
	this->shape.setRadius(radiusSize);
	sf::Color color(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1);
	this->shape.setFillColor(color);

}

void Enemy::initVariables(float startX, float startY)
{
	this->position.x = startX;
	this->position.y = startY;
	if (rand()%2 == 0)
	{
		this->velocity.x = 30;
	}
	else
	{
		this->velocity.x = -30;
	}
}