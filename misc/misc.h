#ifndef SUDOKU_SOLVER_MISC_H
#define SUDOKU_SOLVER_MISC_H

#include "../board/board.h"
#include <time.h>

void print_board(Board *board);

void print_board_debug(Board *board);

void print_time_spent(clock_t begin);

#endif //SUDOKU_SOLVER_MISC_H
