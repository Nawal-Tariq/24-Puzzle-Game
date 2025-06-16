# 🧩 24-Puzzle Game (5x5 Sliding Puzzle) C++ Console Application
Welcome to the 24 Puzzle Game, a C++ console-based implementation of the classic sliding tile puzzle! This is a 5x5 version of the well-known 8 or 15-puzzle game, where the objective is to rearrange shuffled tiles into the correct order by sliding them into an empty space.

🎮 Features
Interactive Console Interface
Simple text-based UI using Windows Console for an engaging game experience.

Random Puzzle Generation
A new puzzle configuration is generated each time you play, using random_shuffle.

Solvability Check
Before gameplay begins, the program checks whether the puzzle is solvable using an inversion count algorithm.

Real-Time Movement
Users control the puzzle using directional keys:

U or u: Move tile up

D or d: Move tile down

L or l: Move tile left

R or r: Move tile right

Goal State Display
Clearly shows the goal state (1 to 24 in order) so players know what they're aiming for.

Legal Move Hints
The program displays all possible legal directions before each move.

Move Tracking & Logging
Every move is recorded in Moves.txt, allowing you to trace your gameplay history.

Victory Message
Displays a celebratory message and the path taken when the goal state is reached.

🛠️ Technologies Used
Language: C++

Compiler: MSVC or compatible C++ compiler

Platform: Windows (uses Windows.h for console enhancements)

Text Coloring: SetConsoleTextAttribute() for a better visual interface

📁 File Structure
main.cpp — Core logic of the game

Moves.txt — Log file automatically generated/appended during play sessions

🚀 Getting Started
Clone the repository:

bash
Copy
Edit
git clone https://github.com/yourusername/24-puzzle-game.git
cd 24-puzzle-game
Build and Run:

Open in Visual Studio or compile via command line:

bash
Copy
Edit
g++ -o PuzzleGame main.cpp
./PuzzleGame
📝 Make sure your environment supports Windows headers (Windows.h) if you're using color and system features.

🎯 Objective
Rearrange the shuffled 5x5 puzzle so the numbers are ordered from 1 to 24 with an empty cell (0) at the bottom-right. Use minimal moves to win!

🤝 Contributions
Pull requests and improvements are welcome! If you'd like to expand features (like auto-solver using A* or better UI), feel free to fork the repo and enhance it.

