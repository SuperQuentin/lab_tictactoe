#include <iostream>

using namespace std;

int main() {

    const char tableau[9] = {
    NULL, NULL, NULL,
    NULL,NULL,NULL,
    NULL,NULL,NULL,
    };

    const short win[8][3] = {
     {0,1,2},
     {2,5,8},
     {6,7,8},
     {0,3,6},
     {3,4,5},
     {1,4,7},
     {0,4,8},
     {2,4,6}
    };

    const char player1 = 'X';
    const char player2 = 'O';


    for(int x = 0; x < sizeof(tableau);x++) {
        auto [index1, index2, index3] = win[x];

        if(tableau[index1] == NULL){
            continue;
        }

        if(tableau[index1] == tableau[index2] && tableau[index2] == tableau[index3]) {
            cout << "c'est gagn\x82, we did it" << endl;
            return true;
        }
    }

    return 0;
}
