#include <stdio.h>

#define BOARDWIDTH 7
#define BOARDHEIGHT 7

char board[BOARDWIDTH][BOARDHEIGHT]  = {
        {'0', '0', '0', '0', '0', '0', '0'},
        {'0', ' ', ' ', ' ', ' ', ' ', '0'},
        {'0', ' ', 'X', 'X', 'X', ' ', '0'},
        {'0', ' ', 'X', 'X', 'X', ' ', '0'},
        {'0', ' ', 'X', 'X', 'X', ' ', '0'},
        {'0', ' ', ' ', ' ', ' ', ' ', '0'},
        {'0', '0', '0', '0', '0', '0', '0'}};

void printBoard();

int checkNeighbours(int, int);

void cycle();

int main() {
    //anfangsmuster ausgeben

    //auswahl muster oder eigenes

        //wenn eigenes, schleife mit koordinatenabfrage

    //

    printBoard();
    printf("\n");
    printf("%d\n", checkNeighbours(3, 3));
    return 0;

}

void cycle(){

    for(int i = 0; i < BOARDWIDTH; i++){
        for(int j = 0; j < BOARDHEIGHT; j++){

            if(board[i][j] == 'X'){

            }
        }
    }


}

int checkNeighbours(int row, int col){

    int x_count = 0;

    for(int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {

            if (i == 0 && j == 0) { continue;}
            if (board[row + i][col + j] == 'X') { x_count += 1; }
        }
    }
}



void printBoard(){
    for(int i = 0; i < BOARDWIDTH; i++) {
        printf("| ");
        for (int j = 0; j < BOARDHEIGHT; j++) {
            printf("%c | ", board[i][j]);
        }
        printf("\n");
    }
}