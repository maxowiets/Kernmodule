#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"

#include "Vector2D.h"
#include "RigidBody.h"
#include "Enemy.h"
#include "Score.h"

#include <iostream>
#include <string>
using namespace std;

class Player : public RigidBody
{
public:
	Player();
	Player(float startX, float startY, float width, float height, float mass, float gravity, float drag, float accelerationForce);
	Player(const Player& original);
	Player& operator=(const Player& original);
	~Player();

	void updateInput();
	void updatePosition();
	void update(const sf::RenderTarget* target, std::vector<Enemy>* enemies, Score* score);
	void render(sf::RenderTarget* target);

	void CheckCollision(std::vector<Enemy>* enemies, Score* score);

private:
	float width;
	float height;
	sf::Texture playerTexture;
	sf::Sprite playerSprite;
	sf::SoundBuffer soundBuffer;
	sf::Sound hitSound;

	void initVariables(float startX, float startY);
	void initShape();
	void initSound();
};

