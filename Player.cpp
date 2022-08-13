#include "Player.h"
#include <cmath>

Player::Player() : RigidBody()
{
	this->playerSprite.setPosition(100, 100);
	this->width = 10;
	this->height = 10;
	this->initVariables(100, 100);
	this->initShape();
	this->initSound();
}

Player::Player(float startX, float startY, float width, float height, float mass, float gravity, float drag, float accelerationForce) : RigidBody(width, height, mass, gravity, drag, accelerationForce)
{
	this->playerSprite.setPosition(startX, startY);
	this->width = width;
	this->height = height;
	this->initVariables(startX, startY);
	this->initShape();
	this->initSound();
}

Player::Player(const Player& original)
{

}

Player& Player::operator=(const Player& original)
{
	width = original.width;
	height = original.height;
	mass = original.mass;
	gravity = original.mass;
	drag = original.drag;
	accelerationForce = original.accelerationForce;
	return *this;
}

Player::~Player()
{

}

void Player::updateInput()
{
	Vector2D movement;
	//Keyboard Input
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		movement.x -= 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		movement.x += 1;
	}


	this->AddForce(movement);
}

void Player::updatePosition()
{
	this->playerSprite.setPosition(this->position.x, this->position.y);
}

void Player::update(const sf::RenderTarget* target, std::vector<Enemy>* enemies, Score* score)
{
	this->CheckCollision(enemies, score);
	this->updateInput();
	this->UpdatePhysics();
	this->CheckWindowBounds(target);
	this->updatePosition();
}

void Player::render(sf::RenderTarget* target)
{
	target->draw(this->playerSprite);
}

void Player::CheckCollision(std::vector<Enemy>* enemies, Score* score)
{

	for (size_t i = 0; i < enemies->size(); i++)
	{
		Vector2D circleDistance;
		circleDistance.x = abs((enemies->at(i).position.x + enemies->at(i).radiusSize) - (this->position.x + this->width * 0.5f));
		circleDistance.y = abs((enemies->at(i).position.y + enemies->at(i).radiusSize) - (this->position.y + this->height * 0.5f));

		if (circleDistance.x > this->width * 0.5f + enemies->at(i).radiusSize) continue;
		if (circleDistance.y > this->height * 0.5f + enemies->at(i).radiusSize) continue;

		if (circleDistance.x <= (this->width * 0.5f)) { enemies->erase(enemies->begin() + i); score->increaseScore(1); hitSound.play(); continue; }
		if (circleDistance.y <= (this->height * 0.5f)) { enemies->erase(enemies->begin() + i); score->increaseScore(1); hitSound.play(); continue; }

		float cornerDistance = (circleDistance.x - this->width * 0.5f) * (circleDistance.x - this->width * 0.5f) + (circleDistance.y - this->height * 0.5f) * (circleDistance.y - this->height * 0.5f);

		cout << cornerDistance << endl;


		if (cornerDistance <= (enemies->at(i).radiusSize * enemies->at(i).radiusSize))
		{
			enemies->erase(enemies->begin() + i);
			score->increaseScore(1);
			hitSound.play();
		}
	}
}

void Player::initVariables(float startX, float startY)
{
	this->position.x = startX;
	this->position.y = startY;
}

void Player::initShape()
{
	if (!this->playerTexture.loadFromFile("Sprites/Player.png")) {}
	this->playerSprite.setTexture(playerTexture);

}

void Player::initSound()
{
	if (!this->soundBuffer.loadFromFile("SFX/HitSound.wav")) {}
	
	this->hitSound.setBuffer(soundBuffer);
}

