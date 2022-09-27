# Pseudo code tictactoe

## Entrée

- Tableau du jeu actuelle
- Valeurs des joueurs

## Sortie

- Win / Lose

## Algo

const tableauWin = [
                    [indexWin1, indexWin2, indexWin3],
                    ...
                   ];

const char player1 = 'X';
const char player2 = 'O';

for(int x = 0; x< tableauWin.length;x++) {
    int index1, index2, index3 = tableauWin[x];

    if(tableau[index1] == null){
        continue;
    }

    if(tableau[index1] == tableau[index2] && tableau[index2] == tableau[index3]) {
        return true;
    }
}

return false;