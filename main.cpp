#include <iostream>
#include <iomanip>
#include <string>
#include <regex>
#include <cmath>


using namespace std;

struct Vector2
{
    int x = 0;
    int y = 0;
};

Vector2 splitCoords(string& rawInput) {
    smatch coords;
    struct Vector2 extractedCoords;

    // Search all corresponding patterns into the input string ex: 3-9, 6-8
    if (regex_match(rawInput, coords,regex("([0-9]-[0-9])"))) {
        string rawCoords = coords[coords.size()-1]; // Get last given cords if there is multiples
        extractedCoords.x = stoi(rawCoords.substr(0,1));
        extractedCoords.y = stoi(rawCoords.substr(2,1));
    }

    return extractedCoords;
}

bool checkValid(char *tableau, int x, int y)
{
    bool isXInbound = x >= 0 && x < 3;
    bool isYInbound = y >= 0 && y < 3;
    if(!isXInbound || !isYInbound) return false;

    int index = y*3+x;
    return (tableau[index] == NULL);
}

bool checkWin(char *tableau)
{
    const short win[8][3] =
    {
            {0,1,2},
            {2,5,8},
            {6,7,8},
            {0,3,6},
            {3,4,5},
            {1,4,7},
            {0,4,8},
            {2,4,6}
    };

    for(int x = 0; x <= 7;x++)
    {
        // https://en.cppreference.com/w/cpp/language/structured_binding
        auto [index1, index2, index3] = win[x];

        if(tableau[index1] == NULL)
        {
            continue;
        }

        if(tableau[index1] == tableau[index2] && tableau[index2] == tableau[index3])
        {
            return tableau[index1];;
        }
    }
    return NULL;
}

void displayTable(const char *tableau)
{
    cout << "+-----------------+" << endl;
    // attention contrairement à .length, le length n'est stocké dans le premier bit
    for(int i = 0; i <= sizeof(tableau); i++)
    {
        int y = i / 3;
        int x = i - (3 * y);

        if(x == 0)
        {
            cout << "|";
            cout << setw(3) << tableau[i] << setw(3);
        }
        else if(x == 2)
        {
            cout << setw(3) << tableau[i] << setw(3);
            cout << "|" << endl;
            cout << "+-----------------+" << endl;
        }
        else
        {
            cout << "|";
            cout << setw(3) << tableau[i] << setw(3);
            cout << "|";
        }
    }
}

int askCoords(char *tableau, char player)
{
    short index = 0;
    bool valide = false;

    while(!valide)
    {
        displayTable(tableau);

        string rawInput;
        cout << "Joueur " << player << " entrée vos cordonnées x-y (Ex: 3-2) :" << endl;
        cin >> rawInput;

        Vector2 coords;

        coords = splitCoords(rawInput);

        valide = checkValid(tableau,coords.x,coords.y); // Vérifie si la case est valide
        if(valide){
            index = coords.y*3+coords.x; // Convertion cordonnées index tableau 1D
        }
    }
    return index;
}

void TheGame(char *tableau)
{
    bool winner = false;
    bool playerTurn = false;
    while(!winner) {
        char player = playerTurn ? 'O' : 'X';
        int playedIndex = askCoords(tableau, player);

        tableau[playedIndex] = player;

        if(checkWin(tableau)){
            cout << "winner" << endl;
            displayTable(tableau);
            //displayWinnerMsg(player);
            winner = true;
        }
        playerTurn = !playerTurn;
    }
}

int main()
{
    char tableau[9] =
    {NULL, NULL, NULL,
    NULL,NULL,NULL,
    NULL,NULL,NULL,
    };

    TheGame(tableau);
    return 0;
}



