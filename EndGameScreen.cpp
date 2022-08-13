#include "EndGameScreen.h"


EndGameScreen::EndGameScreen()
{
	if (!this->font.loadFromFile("Fonts/upheavtt.ttf")) {}
	this->endGameText.setFont(this->font);
	this->endGameText.setFillColor(sf::Color::White);
	this->endGameText.setCharacterSize(124);
	this->endGameText.setString("YOU WON!");
	this->endGameText.setOrigin(this->endGameText.getLocalBounds().width * 0.5f, this->endGameText.getLocalBounds().height * 0.5f);
	this->endGameText.setPosition(400, 250);
}

EndGameScreen::~EndGameScreen()
{

}

void EndGameScreen::EndGameScreenText(string text)
{
	this->endGameText.setString(text);
	this->endGameText.setOrigin(this->endGameText.getLocalBounds().width * 0.5f, this->endGameText.getLocalBounds().height * 0.5f);
}

void EndGameScreen::render(sf::RenderTarget* target)
{
	target->draw(this->endGameText);
}