#include <iostream>
#include <sstream>

using namespace std;

/*
 * Displays the tictactoe grid
 */
string display();
/*
 * Checks if either player has won
 */
void check_winner(char first_grid, char second_grid, char third_grid, char winning_letter);

//Filling the grid with numbers
char grid_1 = '1';
char grid_2 = '2';
char grid_3 = '3';
char grid_4 = '4';
char grid_5 = '5';
char grid_6 = '6';
char grid_7 = '7';
char grid_8 = '8';
char grid_9 = '9';
bool no_winner = true;

int main() {

    //Keeps the while loop and game
    bool keep_running = true;
    char randomize_letter = 'a';

    while(keep_running)
    {
        cout << "Welcome to 2 Player TicTacToe!" << endl;
        cout << "On your own, please decide who will be player one and player two." << endl;
        cout << "Would you like to randomize who goes first? (Please type Y for yes or N for no)" << endl;

        cin >> randomize_letter;

        //Keeps asking for either Y or N if it is not inputted
        while (randomize_letter != 'Y' && randomize_letter != 'N')
        {
            cout << "Sorry, your input is not valid, please input a valid response" << endl;
            cin >> randomize_letter;
        }

        int first_move = 0;

        //If the players choose to randomize the first move, a random player is chosen
        if (randomize_letter == 'Y')
        {
            int first_move = rand() % 2;

            if (first_move == 0)
            {
                cout << "Player one will be going first, his symbol will be X" << endl;
            }
            else
            {
                cout << "Player two will be going first, his symbol will be O" << endl;
            }
        }
        else //Else the players determine who goes first
        {
            cout << "Who would you like to go first? (1 for player one, 2 for player two)." << endl;
            cin >> first_move;

            //Keeps asking for either 1 or 2 if it is not inputted
            while (first_move != 1 && first_move != 2)
            {
                cout << "Sorry, your input is not valid, please input a valid response" << endl;
                cin >> first_move;
            }

            if (first_move == 1)
            {
                cout << "Player one will be going first, their symbol will be X." << endl;
            }
            else
            {
                cout << "Player two will be going first, their symbol will be O." << endl;
            }
        }

        //Explaining the rules and diplaying
        cout << "The spot you would like to mark is done by inputting the number the grid spot it is in." << endl;
        cout << "For example, if you would like to fill the middle grid with your letter, input 5 to fill it in." << endl << endl;
        cout << display() << endl;

        //Creating a vector filled with grids already filled
        vector<int> used_numbers;
        //Number the player wants to input
        int number_to_fill = 0;
        //Boolean to check if the number is used
        bool already_used = false;
        //Either X or O, depending on the player's
        char letter_to_fill = ' ';

        //While no winner has been found
        while(no_winner)
        {
            display();

            if(first_move == 1)
            {
                cout << "Player 1, please input the grid number you would like to fill." << endl;
                letter_to_fill = 'X';
                first_move = 0;
            }
            else if(first_move == 0)
            {
                cout << "Player 2, please input the grid number you would like to fill." << endl;
                letter_to_fill = 'O';
                first_move = 1;
            }

            cin >> number_to_fill;

            //If the number to fill is not 1 through 9, the player is asked for input again
            while(number_to_fill != 1 && number_to_fill != 2 && number_to_fill != 3 &&
                   number_to_fill != 4 && number_to_fill != 5 && number_to_fill != 6 &&
                   number_to_fill != 7 && number_to_fill != 8 && number_to_fill != 9)
            {
                cout << "Sorry, your input is invalid, please input a number you would like to fill." << endl;
                cin >> number_to_fill;
            }

            //Checks if the grid number has been filled yet
            for(int i = 0; i < used_numbers.size(); i++)
            {
                if (number_to_fill == used_numbers[i])
                {
                    already_used = true;
                    break;
                }
            }

            //If the number is already used the player is asked for a new unused grid number
            while(already_used)
            {
                cout << "Sorry, the grid section is already filled, "
                        "please input an empty grid you would like to fill." << endl;
                cin >> number_to_fill;
                already_used = false;
                //Checks if the number is used again
                for(int i = 0; i < used_numbers.size(); i++)
                {
                    //If the number is used, the for loop is broken
                    if(number_to_fill == used_numbers[i])
                    {
                        already_used = true;
                        break;
                    }
                }
            }

            //Switch statement to fill in the grid
            //After the grid is changed to the player's symbol
            //The used grid's number is put in the used number vector
            switch(number_to_fill) {
                case 1:
                    grid_1 = letter_to_fill;
                    used_numbers.push_back(1);
                    break;
                case 2:
                    grid_2 = letter_to_fill;
                    used_numbers.push_back(2);
                    break;
                case 3:
                    grid_3 = letter_to_fill;
                    used_numbers.push_back(3);
                    break;
                case 4:
                    grid_4 = letter_to_fill;
                    used_numbers.push_back(4);
                    break;
                case 5:
                    grid_5 = letter_to_fill;
                    used_numbers.push_back(5);
                    break;
                case 6:
                    grid_6 = letter_to_fill;
                    used_numbers.push_back(6);
                    break;
                case 7:
                    grid_7 = letter_to_fill;
                    used_numbers.push_back(7);
                    break;
                case 8:
                    grid_8 = letter_to_fill;
                    used_numbers.push_back(8);
                    break;
                case 9:
                    grid_9 = letter_to_fill;
                    used_numbers.push_back(9);
                    break;
            }

            cout << endl << display() << endl;

            //Checks if 3 of the grids are in a row
            check_winner(grid_1, grid_2, grid_3, letter_to_fill);
            check_winner(grid_4, grid_5, grid_6, letter_to_fill);
            check_winner(grid_7, grid_8, grid_9, letter_to_fill);
            check_winner(grid_1, grid_4, grid_7, letter_to_fill);
            check_winner(grid_2, grid_5, grid_8, letter_to_fill);
            check_winner(grid_3, grid_6, grid_9, letter_to_fill);
            check_winner(grid_1, grid_5, grid_9, letter_to_fill);
            check_winner(grid_3, grid_5, grid_7, letter_to_fill);

            //If a winner is found, the while loop is broken
            if(!no_winner)
            {
                break;
            }

            //If there is no winner and all grids have been filled, the game ends
            if((grid_1 == 'X' || grid_1 == 'O') && (grid_2 == 'X' || grid_2 == 'O') && (grid_3 == 'X' || grid_3 == 'O') &&
               (grid_4 == 'X' || grid_4 == 'O') && (grid_5 == 'X' || grid_5 == 'O') && (grid_6 == 'X' || grid_6 == 'O') &&
               (grid_7 == 'X' || grid_7 == 'O') && (grid_8 == 'X' || grid_8 == 'O') && (grid_9 == 'X' || grid_9 == 'O'))
            {
                cout << "Unfortunately, all grids have been filled." << endl << endl;
                no_winner = false;
            }
        }
        char play_again = ' ';

        cout << "Would you like to play again? (Please type Y for yes or N for no)" << endl;
        cin >> play_again;

        //If the input is neither Y or N, the player is asked for input again
        while (play_again != 'Y' && play_again != 'N') {
            cout << "Sorry, your input is not valid, please input a valid response" << endl;
            cin >> play_again;
        }

        //If the user inputs N, the while loops is broken
        if (play_again == 'N')
        {
            break;
        }

        //Else the game is reset
        used_numbers.clear();
        grid_1 = '1';
        grid_2 = '2';
        grid_3 = '3';
        grid_4 = '4';
        grid_5 = '5';
        grid_6 = '6';
        grid_7 = '7';
        grid_8 = '8';
        grid_9 = '9';
        no_winner = true;
    }

    cout << "Thank you for playing! Have a good day!" << endl;

    return 0;
}

string display()
{
    stringstream ss;

    ss << " " << grid_1 << " | " << grid_2 << " | " << grid_3 << " " << endl;
    ss << "-----------" << endl;
    ss << " " << grid_4 << " | " << grid_5 << " | " << grid_6 << " " << endl;
    ss << "-----------" << endl;
    ss << " " << grid_7 << " | " << grid_8 << " | " << grid_9 << " " << endl;

    return ss.str();
}

void check_winner(char first_grid, char second_grid, char third_grid, char winning_letter)
{
    //checks if the 3 grids match
    if (first_grid == winning_letter && second_grid == winning_letter && third_grid == winning_letter)
    {
        if (winning_letter == 'X')
        {
            cout << "Player 1 wins!" << endl << endl;
        }
        if (winning_letter == 'O')
        {
            cout << "Player 2 wins!" << endl << endl;
        }
        no_winner = false;
    }
}