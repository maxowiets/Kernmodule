#include <SFML/Graphics.hpp>
#include "Spawner.h"
#include "Player.h"
#include "Score.h"
#include "Enemy.h"
#include "Game.h"

int main()
{
    //Initialize Random Seed
    srand(static_cast<unsigned>(time(0)));

    //Initialize the Game
    Game game;

    //Game Loop
    while(game.running()){
        game.update();
        game.render();
    }

    //End of Application
    return 0;
}