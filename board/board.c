#include "board.h"
#include <stdlib.h>
#include <stdbool.h>


Board initialize_board(int *array) {
    Board *board = (Board *) malloc(sizeof(Board));
    board->_field = (int *) malloc(BOARD_SIZE * BOARD_SIZE * sizeof(int));

    if (board == NULL) exit(-1); // Unable to allocate board
    if (board->_field == NULL) exit(-1); // Unable to allocate field


    for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; ++i) {
        board->_field[i] = array[i];
    }

    return *board;
}

Board copy_board(Board *board) {
    return initialize_board(board->_field);
}

void free_board(Board *board) {
    free(board->_field);
    free(board);
}

bool access_board(Board *board, int x, int y, int *result) {
    if (0 > x || x > BOARD_SIZE) return false; // Out of bounds
    if (0 > y || y > BOARD_SIZE) return false; // Out of bounds

    int index = y * BOARD_SIZE + x;
    *result = board->_field[index];
    return true;
}

bool set_board_value(Board *board, int x, int y, int value) {
    if (0 > x || x > BOARD_SIZE) return false; // Out of bounds
    if (0 > y || y > BOARD_SIZE) return false; // Out of bounds

    int index = y * BOARD_SIZE + x;
    board->_field[index] = value;

    return true;
}

bool find_board_blank(Board *board, int *result_x, int *result_y) {
    for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; i++) {
        if (board->_field[i] != BOARD_BLANK) continue;
        *result_x = i % BOARD_SIZE;
        *result_y = i / BOARD_SIZE;
        return true;
    }
    return false;
}

bool validate_board_horizontal(Board *board, int y) {
    int check_table[10] = {0};
    int value;

    for (int i = 0; i < BOARD_SIZE; i++) {
        access_board(board, i, y, &value);
        if (value == BOARD_BLANK) continue;
        check_table[value]++;
        if (check_table[value] > 1) return false;
    }
    return true;
}

bool validate_board_vertical(Board *board, int x) {
    int check_table[10] = {0};
    int value;

    for (int i = 0; i < BOARD_SIZE; i++) {
        access_board(board, x, i, &value);
        if (value == BOARD_BLANK) continue;
        check_table[value]++;
        if (check_table[value] > 1) return false;
    }
    return true;
}

bool validate_board_square(Board *board, int x, int y) {
    int check_table[10] = {0};
    int value;

    for (int i = x / 3 * 3; i < x / 3 * 3 + 3; i++) {
        for (int j = y / 3 * 3; j < y / 3 * 3 + 3; j++) {
            access_board(board, i, j, &value);
            if (value == BOARD_BLANK) continue;
            check_table[value]++;
            if (check_table[value] > 1) return false;
        }
    }
    return true;
}

bool validate_board(Board *board, int x, int y) {
    return validate_board_horizontal(board, y)
           && validate_board_vertical(board, x)
           && validate_board_square(board, x, y);
}
