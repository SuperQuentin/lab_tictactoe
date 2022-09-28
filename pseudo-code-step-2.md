# Pseudo code tictactoe

## Entrée

- input terminal : ex 1-2, 2-2, 3-1

## Sortie

- Grille du jeu en cours

## Algo

fn displayGrid(tableauDeJeu){
    clearDisplay();
    
    // Affiche le tableau
}



int fn askCoords(char player) {
    short index = 0;
    bool valide = false;

    while(!valide)
    {
        displayGrid(tableauDeJeu);

        cout << "Joueur " << player << " entrée vos cordonnées x-y (Ex: 3-2) :" << endl;
        cin >> cordonnées;

        auto x,y splitCords(cordonnes) // https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/p0144r0.pdf

        valide = checkCoords(x,y); // Vérifie si la case est valide
        if(valide){
            index = y*3+x; // Convertion cordonnées index tableau 1D
        }
    }
    return index;
}

int main() {
    bool playerTurn = false;

    while(!winner) {
        char player = playerTurn ? 'O' : 'X';
        playedIndex = askCoords(player);

        tableauDeJeu[playedIndex] = player;

        if(checkWin(tableauDeJeu)){
            displayGrid(tableauDeJeu);
            displayWinnerMsg(player);
            winner = true;
        } 
        playerTurn = !playerTurn;
    }
    return 0;
}

