#include <iostream>
#include <iomanip>

using namespace std;

struct Vector2
{
    int x = 0;
    int y = 0;
};

bool checkValid(const char *tableau, int x, int y)
{
    bool isXInbound = x >= 0 && x < 3;
    bool isYInbound = y >= 0 && y < 3;
    if(!isXInbound || !isYInbound) return false;

    int index = y*3+x;
    if(tableau[index] != NULL) return false;

    return true;
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



