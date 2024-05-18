#ifndef SUDOKU_SOLVER_BOARD_H
#define SUDOKU_SOLVER_BOARD_H

#include <stdbool.h>
#include "../arena/arena.h"

#define BOARD_SIZE 9
#define BOARD_BLANK 0
#define BOARD_MEM_SIZE (sizeof(Board) + (sizeof(int) * 9 * 9))


typedef struct {
    int *_field;
} Board;

Board initialize_board(const int *array, Arena *arena);

Board copy_board(Board *board, Arena *arena);

bool access_board(Board *board, int x, int y, int *result);

bool set_board_value(Board *board, int x, int y, int value);

bool find_board_blank(Board *board, int *result_x, int *result_y);

bool validate_board_horizontal(Board *board, int y);

bool validate_board_vertical(Board *board, int x);

bool validate_board_square(Board *board, int x, int y);

bool validate_board(Board *board, int x, int y);

#endif //SUDOKU_SOLVER_BOARD_H
