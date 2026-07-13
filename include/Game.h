#pragma once

// The Game class encapsulates all Snake game state and logic.
// It replaces the original global variables with private members,
// which makes the game safe to reason about across multiple files.
class Game
{
public:
    Game();

    // Runs the game loop until gameOver becomes true.
    void Run();

private:
    static const int width = 50;
    static const int height = 20;

    enum eDirection
    {
        STOP = 0,
        LEFT,
        RIGHT,
        UP,
        DOWN
    };

    bool gameOver;
    eDirection dir;

    int x, y;
    int fruitX, fruitY;
    int score;

    int tailX[100], tailY[100];
    int nTail;

    void Setup();
    void Draw();
    void Input();
    void Logic();
};
