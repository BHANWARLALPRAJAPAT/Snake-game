#include "Platform.h"
#include "Game.h"
#include <cstdlib>
#include <ctime>

int main()
{
    srand(static_cast<unsigned>(time(0)));

    InitInput();   // sets up raw/non-blocking terminal mode on Linux/macOS
    Game game;
    game.Run();
    ResetInput();  // restores the terminal on Linux/macOS

    return 0;
}
