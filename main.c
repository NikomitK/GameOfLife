#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

#define BOARDWIDTH 80
#define BOARDHEIGHT 25
#define MOD(a, b) ((((a)%(b))+(b))%(b))

int mode = 0;

void setup();

int checkNeighbours(int, int);

void select();

void setCustomCells();

void printBoard();

void cycle();

void createBoard(char[BOARDHEIGHT][BOARDWIDTH]);

char board[BOARDHEIGHT][BOARDWIDTH];
char boardZwei[BOARDHEIGHT][BOARDWIDTH];

int main() {
    int generation = 0;
    setup();

    while (1) {

        system("cls");
        printf("Dr\x81""cke Str+C zum Beenden\n");
        printf("Generation: %d\n", ++generation);
        printBoard();
        if (mode == 0 && getch() == '\x03') break;
        cycle();


    }
}

void setup() {
    srand(time(NULL));
    system("cls");
    createBoard(board);
    createBoard(boardZwei);
    select();
}

void createBoard(char emptyboard[BOARDHEIGHT][BOARDWIDTH]) {
    for (int i = 0; i < BOARDHEIGHT; i++) {
        for (int j = 0; j < BOARDWIDTH; j++) {
            emptyboard[i][j] = ' ';
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
        for (int j = 0; j < BOARDWIDTH; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}

void select() {

    char input;

    printf("\nBitte Auswahl Treffen: \n     - Blinker = a\n     - Block = b\n     - Bienenstock = c\n     - Leuchtfeuer = d\n     - Gleiter = e\n     - Zuf\x84llig = f\n\nBeliebige andere Taste f\x81r Koordinateneingabe.\n\n");

    input = getch();

    switch (input) {
        case ('a'):
            for (int i = 39; i < 42; i++) board[12][i] = 'X';
            break;
            //Block
        case ('b'):
            board[12][39] = 'X';
            board[12][40] = 'X';
            board[13][39] = 'X';
            board[13][40] = 'X';
            break;
            //Bienenstock
        case ('c'):
            for (int i = 11; i < 15; i++) board[i][39] = 'X';
            break;
            //Leuchtfeuer
        case ('d'):
            board[12][39] = 'X';
            board[12][40] = 'X';
            board[11][39] = 'X';
            board[10][42] = 'X';
            board[9][41] = 'X';
            board[9][42] = 'X';
            break;
            //Gleiter
        case ('e'):
            board[13][40] = 'X';
            board[13][39] = 'X';
            board[13][38] = 'X';
            board[12][40] = 'X';
            board[11][39] = 'X';
            break;
        case ('f'):
            for (int i = 0; i < BOARDHEIGHT; i++) {
                for (int j = 0; j < BOARDWIDTH; j++) {
                    if (rand() % 2) board[i][j] = 'X';
                }
            }
            break;
        default:
            setCustomCells();
            break;
    }

    printf("Bitte Modus ausw\x84hlen: \n     - Manuelles Fortschreiten = 0\n     - Automatisches Fortschreiten = 1");
    input = getch();

    if (input == '1') mode = 1;
}

void setCustomCells() {
    printf("Wie viele Koordinaten willst du eingeben?\n");
    int cont;
    scanf("%d", &cont);
    for (int i = 0; i < cont; i++) {
        printf("Bitte Koordinaten eingeben <zeile spalte>");
        int zeile, spalte;
        scanf("%d %d", &zeile, &spalte);
        if (zeile >= BOARDHEIGHT || spalte >= BOARDWIDTH || zeile == -1 || spalte == -1) {
            printf("Ung\x81ltige Koordinaten, die Spielfeldgr\x94sse betr\x84gt: %d Zeilen und %d Spalten");
        } else {
            board[zeile][spalte] = 'X';
        }
    }
}