#include <iostream>
#include <iomanip>
#include <string>
#include <regex>

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


char checkWin(const char *tableau)
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

    for(int x = 0; x <= sizeof(tableau);x++)
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

int main()
{
    const char tableau[9] =
    {
    'X', NULL, NULL,
    NULL,'X',NULL,
    NULL,NULL,'X',
    };

    char winPlayer = checkWin(tableau);

    if(winPlayer != NULL)
        cout << "tu es bon " << winPlayer << endl;

    displayTable(tableau);

    return 0;
}



