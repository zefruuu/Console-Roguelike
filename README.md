# Console-Roguelike (C++)

This is a simple console-based roguelike game written in C++. The project demonstrates basic game loop mechanics, entity management, and interaction systems using only standard libraries and minimal external dependencies.

Description

The player controls a character on a 2D grid map. The goal is to survive, defeat enemies, collect items, and progress through levels by reaching the door.

The game runs in a loop where the map is redrawn every frame, and the player can move using keyboard input.

Controls

W — move up
S — move down
A — move left
D — move right

Gameplay

* The player starts with a fixed amount of health and damage.
* Enemies spawn randomly on the map:

  * Goblin (low HP and damage)
  * Guard (medium)
  * Gigant (high)
* Items appear randomly:

  * Heal (restores health)
  * Damage Boost (increases damage)
  * Coin (collectible counter)
* When the player steps on an enemy, combat happens automatically.
* When the player steps on an item, it is picked up and applied instantly.
* When the player reaches the door, a new level starts:

  * Player position resets
  * New enemies and items spawn
  * Level counter increases

Game Over

The game ends when the player's health reaches zero.

Technical Details

* Language: C++
* Platform: Windows (uses windows.h and conio.h)
* Rendering: ASCII graphics in console
* Input: _kbhit() and _getch()
* Randomization: rand() with time-based seed
* Game loop: manual loop with screen clearing (system("cls"))

Project Structure

* Entity system using struct Entity
* Separate creation functions for each entity type
* Arrays used to store enemies and items
* Manual memory and index management (no STL containers)
* Basic collision detection using position comparison

Known Limitations

* Uses system("cls") which is slow and platform-dependent
* No dynamic containers (arrays have fixed size)
* No separation into multiple files
* Minimal error handling
* Console flickering may occur

Future Improvements

* Replace system("cls") with a more efficient rendering method
* Use std::vector instead of fixed arrays
* Add enemy movement and AI
* Add inventory system
* Improve combat mechanics
* Add menus and UI improvements
* Cross-platform support

Build and Run

Compile with a C++ compiler (for example, g++):

g++ main.cpp -o game

Run:

game.exe

Author

First version of a console roguelike project. Designed as a learning project for understanding game loops, structs, and basic game architecture in C++.

