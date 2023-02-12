#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BOARDWIDTH 80
#define BOARDHEIGHT 25
#define MOD(a,b) ((((a)%(b))+(b))%(b))

int checkNeighbours(int, int);
void select();
void setCustomCells();
void printBoard();
void cycle();
void createBoard(char[BOARDHEIGHT][BOARDWIDTH]);

char board[BOARDHEIGHT][BOARDWIDTH];
char boardZwei[BOARDHEIGHT][BOARDWIDTH];

int main() {

    createBoard(board);
    createBoard(boardZwei);
    select();


    while(1) {

        cycle();
        printBoard();
        sleep(1);
        system("cls");

    }
}

void createBoard(char emptyboard[BOARDHEIGHT][BOARDWIDTH]){
    for(int i = 0; i<BOARDHEIGHT; i++){
        for(int j = 0; j<BOARDWIDTH; j++){
            emptyboard[i][j] = ' ';
        }
    }
}

void cycle(){

    for(int i = 0; i < BOARDHEIGHT; i++){
        for(int j = 0; j < BOARDWIDTH; j++){

                int neigh = checkNeighbours(i, j);

                if(board[i][j] == 'X'){
                    if(neigh == 2 || neigh == 3) boardZwei[i][j] = 'X';
                    else boardZwei[i][j] = ' ';
                }

                if(board[i][j] == ' '){
                    if(neigh == 3) boardZwei[i][j] = 'X';
                    else boardZwei[i][j] = ' ';
                }
            }
        }

    for(int i = 0; i < BOARDHEIGHT; i++){
        for(int j = 0; j < BOARDWIDTH; j++) {

            board[i][j] = boardZwei[i][j];
        }
    }
}

int checkNeighbours(int row, int col){

    int x_count = 0;

    for(int i = row-1; i <= row+1; i++) {
        for (int j = col-1; j <= col+1; j++) {
            if (i == row && j == col) continue;
            if (board[MOD(i, BOARDHEIGHT)][MOD(j, BOARDWIDTH)] == 'X') x_count += 1;

        }
    }

    return x_count;
}

void printBoard(){
    for(int i = 0; i < BOARDHEIGHT; i++) {
        for (int j = 0; j < BOARDWIDTH; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}

void select() {

    int a;

    printf("Bitte Auswahl Treffen: \n     - Blinker = 1\n     - Block = 2\n     - Bienenstock = 3\n     - Leuchtfeuer = 4\n     - Gleiter = 5\n\nBeliebige andere Taste f\u00dcr Koordinateneingabe.\n\n");
    scanf("%d", &a);



    switch (a) {
        //Blinker
        case (1):
            for (int i = 39; i < 42; i++) board[12][i] = 'X';
            break;
        //Block
        case (2):
            board[12][39] = 'X';
            board[12][40] = 'X';
            board[13][39] = 'X';
            board[13][40] = 'X';
            break;
        //Bienenstock
        case (3):
            for (int i = 11; i < 15; i++) board[i][39] = 'X';
            break;
        //Leuchtfeuer
        case (4):
            board[12][39] = 'X';
            board[12][40] = 'X';
            board[11][39] = 'X';
            board[10][42] = 'X';
            board[9][41] = 'X';
            board[9][42] = 'X';
            break;
        //Gleiter
        case (5):
            board[13][40] = 'X';
            board[13][39] = 'X';
            board[13][38] = 'X';
            board[12][40] = 'X';
            board[11][39] = 'X';
            break;
        default:
            setCustomCells();
    }

}

void setCustomCells(){
    printf("Wie viele Koordinaten willst du eingeben?");
    int cont;
    scanf("%d", &cont);
    for(int i = 0; i<cont; i++){
        printf("Bitte Koordinaten eingeben <zeile spalte>");
        int zeile, spalte;
        scanf("%d %d", &zeile, &spalte);
        if(zeile >= BOARDHEIGHT || spalte >= BOARDWIDTH || zeile == -1 || spalte == -1){
            printf("Ungültige Koordinaten, die Spielfeldgroesse beträgt: %d Zeilen und %d Spalten");
        } else {
            board[zeile][spalte] = 'X';
        }
    }
}