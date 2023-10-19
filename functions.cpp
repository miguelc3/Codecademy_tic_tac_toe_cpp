#include <iostream>
#include <vector>
#include <string>
using namespace std;

void greet() {
    cout << "      ======================== \n";
    cout << "       Let's play tic tac toe \n";
    cout << "      ======================== \n";
}

// Function to print white spaces
string n_spaces(int nr_spaces) {

    string n_spaces(nr_spaces, ' ');
    return n_spaces;

}

// Inicializate vectore to store values of each space -> initial value for each position is just a space
vector<string> grid(9);

void show_grid(vector<string> grid_field) {
    cout << "\n \n";
    cout << "Game: " << n_spaces(13) << "Field references:"; 
    cout << "\n";
    cout << " " << grid_field[0] << " | " << grid_field[1] << " | " << grid_field[2] << n_spaces(8) << " 0 | 1 | 2 \n";
    cout << "-----------" << n_spaces(8) << "-----------\n";
    cout << " " << grid_field[3] << " | " << grid_field[4] << " | " << grid_field[5] << n_spaces(8) << " 3 | 4 | 5 \n";
    cout << "-----------" << n_spaces(8) << "-----------\n";
    cout << " " << grid_field[6] << " | " << grid_field[7] << " | " << grid_field[8] << n_spaces(8) << " 6 | 7 | 8 \n";

}


bool is_winner() {

    if (grid[0] == grid[1] && grid[1] == grid[2] && grid[0] != " ") {
        return true;
    } else if (grid[3] == grid[4] && grid[4] == grid[5] && grid[3] != " ") {
        return true;
    } else if (grid[6] == grid[7] && grid[7] == grid[8] && grid[6] != " ") {
        return true;
    } else if (grid[0] == grid[3] && grid[3] == grid[6] && grid[0] != " ") {
        return true; 
    } else if (grid[1] == grid[4] && grid[4] == grid[7] && grid[1] != " ") {
        return true;
    } else if (grid[2] == grid[5] && grid[5] == grid[8] && grid[2] != " ") {
        return true;
    } else if (grid[0] == grid[4] && grid[4] == grid[8] && grid[0] != " ") {
        return true;
    } else if (grid[2] == grid[4] && grid[4] == grid[6] && grid[2] != " ") {
        return true;
    } else {
        return false;
    }
    

}

void game() {

    grid[0] = " ";
    grid[1] = " ";
    grid[2] = " ";
    grid[3] = " ";
    grid[4] = " ";
    grid[5] = " ";
    grid[6] = " ";
    grid[7] = " ";
    grid[8] = " ";    
    
    string symbol;
    string player_now;
    bool is_win;

    int c = 1;
    while (1) {
        show_grid(grid);        
        
        if (c % 2 == 1) {
            cout << "Player 1, it's your turn, where do you want to play?\n";
            symbol = "x";
            player_now = "Player 1";
        } else if (c % 2 == 0) {
            cout << "Player 2, it's your turn, where do you want to play?\n";
            symbol = "o";
            player_now = "Player 2";
        } 

        int field;
        cout << "Field: ";
        cin >> field;
        cout << "\n";
        
        grid[field] = symbol;

        // show_grid(grid);

        is_win = is_winner();
        if (is_win) {
            cout << player_now << " won. Congratulations!";
            break;
        }

        c += 1;
        
    }

    
}

