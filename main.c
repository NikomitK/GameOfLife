#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BOARDWIDTH 5
#define BOARDHEIGHT 5

#define MOD(a, b) ((((a)%(b))+(b))%(b))

void createBoards();

char board[BOARDHEIGHT][BOARDWIDTH];
char boardZwei[BOARDHEIGHT][BOARDWIDTH];

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

void printBoard();

int checkNeighbours(int, int);

void cycle();

/*
 * checkNeigh gibt x um eine zelle herum zurück
 * in cycle je nach inhalt und neighbours zelle in neuem board verwalten
 * altes board durch neues ersetzen
 */
int main() {
    createBoards();
    printBoard();
    //anfangsmuster ausgeben

    //auswahl muster oder eigenes

    //wenn eigenes, schleife mit koordinatenabfrage


    while (1) {
        checkNeighbours(1, 0);
        cycle();
        printBoard();
        sleep(5);
        system("cls");

    }
    return 0;

}

void createBoards() {
    for (int i = 0; i < BOARDHEIGHT; i++) {
        for (int j = 0; j < BOARDWIDTH; j++) {
            board[i][j] = ' ';
            boardZwei[i][j] = ' ';
        }
    }
}

void cycle() {

    for (int i = 0; i < BOARDHEIGHT; i++) {
        for (int j = 0; j < BOARDWIDTH; j++) {

            int neigh = checkNeighbours(i, j);

            if (board[i][j] == 'X') {
                if (neigh == 2 || neigh == 3) boardZwei[i][j] = 'X';
                else boardZwei[i][j] = ' ';
            }

            if (board[i][j] == ' ') {
                if (neigh == 3) boardZwei[i][j] = 'X';
                else boardZwei[i][j] = ' ';
            }
        }
    }

    for (int i = 0; i < BOARDHEIGHT; i++) {
        for (int j = 0; j < BOARDWIDTH; j++) {

            board[i][j] = boardZwei[i][j];
        }
    }
}

int checkNeighbours(int row, int col) {

    int x_count = 0;

    for (int i = row - 1; i <= row + 1; i++) {
        for (int j = col - 1; j <= col + 1; j++) {
            if (i == row && j == col) continue;
            if (board[MOD(i, BOARDHEIGHT)][MOD(j, BOARDWIDTH)] == 'X') x_count += 1;

        }
    }

    return x_count;
}


void printBoard() {
    for (int i = 0; i < BOARDHEIGHT; i++) {
        printf("| ");
        for (int j = 0; j < BOARDWIDTH; j++) {
            printf("%c | ", board[i][j]);
        }
        printf("\n");
    }
}