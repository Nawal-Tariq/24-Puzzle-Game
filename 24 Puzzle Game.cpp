#include<iostream>
#include<conio.h>
#include<cstdlib> 
#include <algorithm> 
#include<ctime>
#include<string>
#include<fstream>
#include <Windows.h>

using namespace std;
void init(int initial[5][5]);
void goal(int goal[5][5]);
bool IsSolveable(int solve[5][5]);
bool is_goal(int current[5][5], int goal[5][5]);
void init(int initial[5][5])
{
	srand(time(0));

	// Generate shuffled numbers from 1 to 24
	int num[24];
	for (int i = 0; i < 24; ++i)
	{
		num[i] = i + 1;
	}
	random_shuffle(num, num + 24);

	// Assign shuffled numbers to grid cells
	int index = 0;
	int emptyRow = rand() % 5; // Randomly select a row
	int emptyCol = rand() % 5; // Randomly select a column
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			if (i == emptyRow && j == emptyCol)
			{
				initial[i][j] = 0; // Leave this cell empty
			}
			else
			{
				initial[i][j] = num[index++];
			}
		}
	}
}
void goal(int goals[5][5])
{
	cout << "\t\t\t\t\t\t\t\t\t\t\t" << endl;
	srand(time(0));
	cout << "\t " << "-------------------------------------" << endl;
	int num = 1; 
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (i == 4 && j == 4)
			{
				cout << "\t" <<" "<< " |" << " " << " | ";
				goals[i][j] = 0; 
			}
			else
			{
				goals[i][j] = num++; 
				cout << "\t" << " |" << goals[i][j] << " |"; 
			}
		}
		cout << endl;
		cout << "\t " << "-------------------------------------" << endl;
	}

	cout << "\t\t\t" << "Goal State" << endl;
}
bool isSolvable(int solve[5][5])
{
	int inversions = 0;
	int flatArr[5 * 5];
	int num = 0;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (solve[i][j] != 0)
			{
				flatArr[num++] = solve[i][j];
			}
		}
	}
	for (int i = 0; i < 5 * 5 - 1; i++)
	{
		for (int j = i + 1; j < 5 * 5; j++)
		{
			if (flatArr[i] > flatArr[j])
			{
				inversions++;
			}
		}
	}
	if (5 % 2 == 1)
	{
		return inversions % 2 == 0;
	}
	else
	{
		return false;
	}
}

bool is_goal(int initial[5][5], int goal[5][5])
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (initial[i][j] != goal[i][j])
			{
				return false;
			}
		}
	}
	return true;
}
int* legal_moves(int* init_state)
{
	int empty_row = -1, empty_col = -1;
	
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (init_state[i * 5 + j] == 0)
			{
				empty_row = i;
				empty_col = j;
				break;
			}
		}
	}
	int* moves = new int[4]; // Up, Down, Left, Right
	
	for (int i = 0; i < 4; i++) 
	{
		moves[i] = 0;
	}
	
	if (empty_row > 0)
	
	{
		moves[0] = 1; // Up
	}
	if (empty_row < 4)
	{
		moves[1] = 1; // Down
	}
	if (empty_col > 0)
	{
		moves[2] = 1; // Left
	}
	if (empty_col < 4)
	{
		moves[3] = 1; // Right
	}
	return moves;
}
void make_move(int(&init_state)[5][5], char move)
{
	int empty_row = -1, empty_col = -1; 
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (init_state[i][j] == 0)
			{
				empty_row = i;
				empty_col = j;
				break;
			}
		}
	}
	switch (move)
	{
	case 'U': // Move up
	case 'u':
		if (empty_row > 0)
		{
			swap(init_state[empty_row][empty_col], init_state[empty_row - 1][empty_col]);
		}
		break;
	case 'D': // Move down
	case 'd':
		if (empty_row < 4)
		{
			swap(init_state[empty_row][empty_col], init_state[empty_row + 1][empty_col]);
		}
		break;
	case 'L': // Move left
	case 'l':
		if (empty_col > 0)
		{
			swap(init_state[empty_row][empty_col], init_state[empty_row][empty_col - 1]);
		}
		break;
	case 'R': // Move right
	case 'r':
		if (empty_col < 4)
		{
			swap(init_state[empty_row][empty_col], init_state[empty_row][empty_col + 1]);
		}
		break;
	}
}

void print_path(const char moves[], int num_moves)
{
	cout << "Moves taken to reach the goal state:" << endl;
	for (int i = 0; i < num_moves; ++i)
	{
		cout << moves[i] << " ";
	}
	cout << endl;
}

int main()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << endl << endl;
	cout << "\t\t\t\t\t" << endl;
	cout << endl << endl;
	SetConsoleTextAttribute(h, 11);
	cout << "\t\t\t\t\t" << "Welcome! to the 24-Puzzle Game :)" << "\t" << endl;
	// Main game loop
	char replay = 'y';
	while (replay == 'y' || replay == 'Y')
	{
		cout << "\t\t\t\t\t" << endl;
		cout << endl;
		cout << endl;
		SetConsoleTextAttribute(h, 12); /// function for text color parrot
		int game;
		
		cout << "\t\t\t\t\t|+++++++++++++++++++++|" << endl;
		cout << "\t\t\t\t\t|     GAME MENU       |" << endl;
		cout << "\t\t\t\t\t|    1. Play Game     |" << endl;
		cout << "\t\t\t\t\t|    2. Exit          |" << endl;
		cout << "\t\t\t\t\t|_____________________|" << endl;
		cout << endl;
		cout << "\t\t\t\t\t"<<"Choose a number" << "\t\t\t\t\t"<<endl;
		cout << "\t\t\t\t";
		cin >> game;
	
		if (game == 1)
		{
			
			char moves[100];
			int initial[5][5];
			int goals[5][5];
			init(initial);
			int num_moves = 0;
			ofstream out("Moves.txt", ios::app); // Open the file in append mode
			cout << "\t\t\t\t\t\t\t\t\t\t\t" << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t\t" << endl;
			SetConsoleTextAttribute(h, 2); //function for text color default
			cout << "\t " << "-------------------------------------" << "\t\t\t\t" << endl;
			// Main game loop
			while (!is_goal(initial, goals))
			{
				char move;
				bool valid_move = false;
				// Display the grid
				SetConsoleTextAttribute(h, 2);
				for (int i = 0; i < 5; ++i)
				{
					for (int j = 0; j < 5; ++j)
					{
						if (initial[i][j] == 0)
						{
							cout << "\t" << " |" << " " << " | "; // Display empty cell
						}
						else
						{
							cout << "\t" << " |" << initial[i][j] << " | ";
						}
					}
					cout << endl;
					cout << "\t " << "-------------------------------------" << endl;
				}
				cout << "\t\t\t" << "Initial State" << endl;
				SetConsoleTextAttribute(h, 3);
				goal(goals);
				cout << endl;
				cout << endl;
				SetConsoleTextAttribute(h, 11);
				if (isSolvable(initial))
				{
					cout << "\t\t\t\t\t" << "Puzzle is solvable!" << endl;
				}
				else
				{
					cout << "\t\t\t\t\t" << "Puzzle is not solvable." << endl;
				}
				int* Moves = legal_moves(initial[0]);
				cout << "Legal moves:\n";
				if (Moves[0] == 1)
				{
					cout << "Up\n";
				}
				if (Moves[1] == 1)
				{
					cout << "Down\n";
				}
				if (Moves[2] == 1)
				{
					cout << "Left\n";
				}
				if (Moves[3] == 1)
				{
					cout << "Right\n";
				}
				// Loop until a valid move is entered
				while (!valid_move)
				{
					cout << "\nEnter your move (U/D/L/R for Up/Down/Left/Right): ";
					cin >> move;
					// Validate the move
					if (move == 'U' || move == 'u' || move == 'd' || move == 'D' || move == 'L' || move == 'l' || move == 'R' || move == 'r')
					{
						valid_move = true;
						out << move << "\n ";  // Write the move to the file
						make_move(initial, move);
						moves[num_moves] = move; // Store the move in the array
						++num_moves; // Increment the number of moves

					}
					else
					{
						cout << "Invalid move! Please enter a valid move from (U/D/L/R)." << endl;

					}
				}
				out.close(); // Close the file after writing each move
				system("cls");
				SetConsoleTextAttribute(h, 2);
				cout << "\nUpdated State after moving " << move << ":" << endl;
				cout << "\t " << "-------------------------------------" << endl;

			}

			print_path(moves, num_moves);
			SetConsoleTextAttribute(h, 5);
			cout << "\nCongratulations! You solved the puzzle!" << endl;
		}
		else if (game == 2)
		{
			SetConsoleTextAttribute(h, 6);
			cout <<"\t\t\t\t\t\t "<<"BYE BYE !" << endl;
			break; // Exit the loop and end the program
		}
		else
		{
			cout << "Invalid choice! Please choose again." << endl;
		}

		cout << "Do you want to play again? (y/n): ";
		cin >> replay;
	}

	system("pause");
	return 0;
}   
