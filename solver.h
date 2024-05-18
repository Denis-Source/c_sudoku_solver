#ifndef SUDOKU_SOLVER_SOLVER_H
#define SUDOKU_SOLVER_SOLVER_H

#include "board/board.h"

#define CHECK_TABLE_SIZE 30
#define CHECK_TABLE_ROW 10
#define TEST_STACK_SIZE 100

typedef struct {
    int *_storage;
} CheckTable;

CheckTable initialize_check_table();

bool solve_board(Board *initial_board, Arena *arena);

#endif //SUDOKU_SOLVER_SOLVER_H
