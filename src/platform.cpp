#include "Platform.h"
#include <iostream>

#ifdef _WIN32

// ---------------------------------------------------------------------
// Windows implementation
// ---------------------------------------------------------------------
#include <conio.h>
#include <cstdlib>

void InitInput() { /* nothing to do on Windows */ }
void ResetInput() { /* nothing to do on Windows */ }

void ClearScreen()
{
    system("cls");
}

bool KeyHit()
{
    return _kbhit() != 0;
}

int GetKey()
{
    return _getch();
}

#else

// ---------------------------------------------------------------------
// Linux / macOS (POSIX) implementation
// ---------------------------------------------------------------------
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <cstdio>

static termios g_oldTermios;

void InitInput()
{
    termios t;
    tcgetattr(STDIN_FILENO, &t);
    g_oldTermios = t;

    // Disable canonical mode (so we don't wait for Enter) and echo.
    t.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &t);

    // Make stdin reads non-blocking.
    int flags = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, flags | O_NONBLOCK);
}

void ResetInput()
{
    tcsetattr(STDIN_FILENO, TCSANOW, &g_oldTermios);
}

void ClearScreen()
{
    // ANSI escape codes: clear screen, move cursor to top-left.
    std::cout << "\x1B[2J\x1B[H";
}

bool KeyHit()
{
    char c;
    int n = read(STDIN_FILENO, &c, 1);
    if (n > 0)
    {
        ungetc(c, stdin);
        return true;
    }
    return false;
}

int GetKey()
{
    char c = 0;
    read(STDIN_FILENO, &c, 1);
    return c;
}

#endif
