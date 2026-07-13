#pragma once

// Cross-platform console utilities.
//
// On Windows this wraps conio.h's _kbhit()/_getch() and system("cls").
// On Linux/macOS this puts the terminal into raw, non-blocking mode
// using termios so keys can be read the same way, without waiting
// for the user to press Enter.

// Call once at program start (sets up raw terminal mode on POSIX).
void InitInput();

// Call once at program exit (restores the terminal on POSIX).
void ResetInput();

// Clears the console screen.
void ClearScreen();

// Returns true if a key is currently waiting to be read.
bool KeyHit();

// Reads and returns a single key press (blocking read of 1 byte).
int GetKey();
