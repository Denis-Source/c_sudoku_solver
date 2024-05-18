#include <time.h>
#include "stdio.h"
#include "misc.h"
#include "../board/board.h"

void print_board(Board *board) {
    int value;
    printf("======================\n");
    for (int y = 0; y < BOARD_SIZE; y++) {
        printf("= ");
        for (int x = 0; x < BOARD_SIZE; x++) {
            access_board(board, x, y, &value);
            if (value != BOARD_BLANK) printf("%d ", value);
            else printf(". ");
        }
        printf(" =\n");
    }
    printf("======================\n\n");
}

void print_board_debug(Board *board) {
    int value;
    printf("{\n");
    for (int y = 0; y < BOARD_SIZE; y++) {
        printf("    ");
        for (int x = 0; x < BOARD_SIZE; x++) {
            access_board(board, x, y, &value);
            printf("%d, ", value);
        }
        printf("\n");
    }
    printf("}\n\n");
}

void print_time_spent(clock_t begin) {
    clock_t end = clock();
    double time_spent = (double) (end - begin) / CLOCKS_PER_SEC;
    printf("Seconds spent: %f\n", time_spent);
}