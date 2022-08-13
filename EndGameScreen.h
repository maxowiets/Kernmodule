#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"
#include <iostream>
using namespace std;
class EndGameScreen
{
private:
	sf::Font font;
	sf::Text endGameText;
public:
	EndGameScreen();
	~EndGameScreen();

	void EndGameScreenText(string text);
	void render(sf::RenderTarget* target);
};