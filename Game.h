#pragma once
#include "Player.h"
#include "Enemy.h"
#include "Score.h"
#include "EndGameScreen.h"
#include <vector>

class Game
{
private:
	sf::VideoMode videoMode;
	sf::RenderWindow* window;
	bool endGame;
	sf::Event sfmlEvent;

	Player player = Player(390, 520, 100, 80, 1, 0, 0.1, 5);
	EndGameScreen endGameScreen;
	int spawnTimer;
	int spawnTime;
	sf::Texture* enemyTexture = new sf::Texture();

	void gameWon();
	void spawnEnemies();
	void enemyOutOfScreen();
	void initVariables();
	void initWindow();

public:
	//Constructor and Destructor
	Game();
	~Game();

	//Functions
	const bool running() const;
	void pollEvents();
	void update();
	void render();

	Score* score = new Score();
	std::vector<Enemy>* enemies = new std::vector<Enemy>();
};