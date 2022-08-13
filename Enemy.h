#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"

#include "RigidBody.h"
#include "Score.h"


#include <iostream>
using namespace std;

class Enemy : public RigidBody
{
public:
	Enemy();
	Enemy(float radiusSize);
	Enemy(float startX, float startY, float radiusSize, sf::Texture* enemyTexture, float mass, float gravity, float drag, float accelerationForce);
	~Enemy();

	//Functions
	void updatePosition();
	void update(const sf::RenderTarget* target);
	void render(sf::RenderTarget* target);

	float radiusSize;
private:
	sf::CircleShape shape;
	sf::Sprite enemySprite;

	void initShape();
	void initVariables(float startX, float startY);
};

