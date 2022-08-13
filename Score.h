#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"
class Score
{
public:
	Score();
	~Score();
	void increaseScore(int amount);
	void render(sf::RenderTarget* target);
	int score;
private:
	sf::Font font;
	sf::Text scoreText;
};

