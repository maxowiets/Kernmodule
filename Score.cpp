#include "Score.h"

Score::Score()
{
	this->font.loadFromFile("Fonts/upheavtt.ttf");
	this->scoreText.setFont(this->font);
	this->scoreText.setFillColor(sf::Color::White);
	this->scoreText.setCharacterSize(124);
	this->score = 0;
	this->scoreText.setString(std::to_string(score));
	this->scoreText.setPosition(30, -30);
}

Score::~Score()
{

}

void Score::increaseScore(int amount)
{
	this->score += amount;
	this->scoreText.setString(std::to_string(score));
}

void Score::render(sf::RenderTarget* target)
{
	target->draw(this->scoreText);
}