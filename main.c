#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BOARDWIDTH 5
#define BOARDHEIGHT 5

char board[BOARDWIDTH][BOARDHEIGHT]  = {
        {' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', 'X'},
        {' ', ' ', ' ', ' ', 'X'},
        {' ', ' ', ' ', ' ', 'X'},
        {' ', ' ', ' ', ' ', ' '}};

void printBoard();

int checkNeighbours(int, int);

void cycle();
/*
 * checkNeigh gibt x um eine zelle herum zurück
 * in cycle je nach inhalt und neighbours zelle in neuem board verwalten
 * altes board durch neues ersetzen
 */
int main() {
    //anfangsmuster ausgeben

    //auswahl muster oder eigenes

        //wenn eigenes, schleife mit koordinatenabfrage
    checkNeighbours(1, 4);
    int i = 0;
    while(i < 100) {
        cycle();
        printBoard();
        sleep(3);
        system("cls");
        i++;
    }
    return 0;

}

void cycle(){
    char boardZwei[BOARDWIDTH][BOARDHEIGHT] = {
            {' ', ' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' ', ' '}};

    for(int i = 0; i < BOARDWIDTH; i++){
        for(int j = 0; j < BOARDHEIGHT; j++){

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

    for(int i = 0; i < BOARDWIDTH; i++){
        for(int j = 0; j < BOARDHEIGHT; j++) {

            board[i][j] = boardZwei[i][j];
        }
    }
}

int checkNeighbours(int row, int col){

    int x_count = 0;

    for(int i = -1; i <= 1; i++) {
        int tempi = i;
        //checkOutOfBounds für i eventuell auslagern
        if(row + tempi == -1) tempi = BOARDHEIGHT - 1;
        if(row + tempi == BOARDHEIGHT) tempi = BOARDHEIGHT - 1;
        for (int j = -1; j <= 1; j++) {
            int tempj = j;
            //checkOutOfBounds für j eventuell auslagern
            if(col + tempj == -1) tempj = BOARDWIDTH - 1;
            if(col + tempj == BOARDWIDTH) tempj = BOARDWIDTH - 1;
            if (i == 0 && j == 0) continue;
            //printf("%d//%d//", tempj, tempi);
            if (board[row + tempi][col + tempj] == 'X'){
                x_count += 1;
                //printf("gefunden\n");
                }
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