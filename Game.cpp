#include "Game.h"

void Game::gameWon()
{
	if (this->score->score >= 10)
	{
		this->endGameScreen.EndGameScreenText("YOU WIN! :)");
		this->endGame = true;
	}	
	if (this->score->score <= -10)
	{
		this->endGameScreen.EndGameScreenText("YOU LOST :(");
		this->endGame = true;
	}
}

void Game::spawnEnemies()
{
	this->spawnTimer++;
	if (this->spawnTimer >= this->spawnTime)
	{
		this->spawnTimer = 0;
		enemies->push_back(Enemy(rand() % (this->window->getSize().x - 200), -100, 20, this->enemyTexture, 1, 0.5, 0, 0));
	}
}

void Game::enemyOutOfScreen()
{
	for (size_t i = 0; i < this->enemies->size(); i++)
	{
		if (this->enemies->at(i).position.y >= this->window->getSize().y)
		{
			this->enemies->erase(enemies->begin() + i);
			score->increaseScore(-1);
		}
	}
}

void Game::initVariables()
{
	this->endGame = false;
	this->spawnTime = 40;
	this->spawnTimer = this->spawnTime;
	if (!this->enemyTexture->loadFromFile("Sprites/Enemy.png")) {}

}

void Game::initWindow()
{
	this->videoMode = sf::VideoMode(800, 600);
	this->window = new sf::RenderWindow(this->videoMode, "Kernmodule", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(60);
}

//Constructors and Destructors
Game::Game()
{
	this->initVariables();
	this->initWindow();
}

Game::~Game()
{
	delete this->window;
	delete this->score;
	delete this->enemies;
	delete this->enemyTexture;
}

//Functions
const bool Game::running() const
{
	return this->window->isOpen();
}

void Game::pollEvents()
{
	while (this->window->pollEvent(this->sfmlEvent))
	{
		switch (this->sfmlEvent.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->sfmlEvent.key.code == sf::Keyboard::Escape)
			{
				this->window->close();
			}
			break;
		}
	}
}

void Game::update()
{
	this->pollEvents();

	if (!this->endGame)
	{
		this->gameWon();
		this->spawnEnemies();
		this->enemyOutOfScreen();
		this->player.update(this->window, this->enemies, this->score);

		for (int i = 0; i < enemies->size(); i++)
		{
			enemies->at(i).update(this->window);
		}
	}
}

void Game::render()
{
	this->window->clear();

	//Render Stuff
	if (!this->endGame)
	{
		this->player.render(this->window);
		for (int i = 0; i < enemies->size(); i++)
		{
			enemies->at(i).render(this->window);
		}
		this->score->render(this->window);
	}
	else
	{
		this->endGameScreen.render(this->window);
	}
	this->window->display();
}
