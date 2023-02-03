#include <stdio.h>

#define BOARDWIDTH 5
#define BOARDHEIGHT 5

char board[BOARDWIDTH][BOARDHEIGHT]  = {
        {'X', 'X', ' ', ' ', 'X'},
        {'X', 'X', ' ', ' ', 'X'},
        {'X', ' ', ' ', ' ', ' '},
        {'X', ' ', ' ', ' ', 'X'},
        {'X', 'X', ' ', ' ', 'X'}};

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
    printf("%d\n", checkNeighbours(0, 0));
    return 0;

}

void cycle(){
    char boardZwei[BOARDWIDTH][BOARDHEIGHT] =
    {
        {'X', ' ', ' ', ' ', ' '},
        {'X', ' ', ' ', ' ', ' '},
        {'X', ' ', ' ', ' ', ' '},
        {'X', ' ', ' ', ' ', ' '},
        {'X', ' ', ' ', ' ', ' '}};

    for(int i = 1; i < BOARDWIDTH-1; i++){
        for(int j = 1; j < BOARDHEIGHT-1; j++){

            if(board[i][j] == 'X'){
                int neigh = checkNeighbours(i, j);

            }
        }
    }
}

int checkNeighbours(int row, int col){

    int x_count = 0;

    for(int i = -1; i <= 1; i++) {
        int tempi = i;
        //checkOutOfBounds fr i eventuell auslagern
        if(row + tempi == -1) tempi = BOARDHEIGHT-1;
        if(row + tempi == BOARDHEIGHT + 1) tempi = 0;
        for (int j = -1; j <= 1; j++) {
            int tempj = j;
            //checkOutOfBounds für j eventuell auslagern
            if(col + tempj == -1) tempj = BOARDWIDTH-1;
            if(col + tempj == -1) tempj = 0;
            if (i == 0 && j == 0) continue;
            printf("%d//%d//", tempj, tempi);
            if (board[row + tempi][col + tempj] == 'X'){
                x_count += 1;
                printf("gefunden\n");}
        }
    }

    return x_count;
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