#include "Game.h"

//having fun not doing anything in the main.cpp file :)
int main()
{
    //random time counter
    srand((unsigned)time(NULL));

    /*
    int level = 5;
    int x = static_cast<int>(pow(level, 3) + 5);
    std::cout << x << std::endl;
    */

    //class object
    Game game;
    game.initGame();

    /*
    Inventory inv;
    inv.addItem(Item());
    inv.addItem(Item());
    inv.addItem(Item());
    inv.addItem(Item());
    inv.addItem(Item());
    inv.addItem(Item());
    inv.addItem(Item());
    inv.debugPrint();
    */

    while (game.getPlaying())
    {
        //system("CLS");
        game.mainMenu();
    }
    return 0;
}
