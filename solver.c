#include <stdbool.h>
#include "board/board.h"
#include "solver.h"
#include "stack/stack.h"
#include "stdio.h"
#include "arena/arena.h"
#include "misc/misc.h"


bool solve_board(Board *initial_board, Arena *arena) {
    int x, y;
    BoardStack board_stack = initialize_board_stack(TEST_STACK_SIZE);
    Board board_candidate, new_board_candidate;

    push_board_stack(&board_stack, initial_board);
    while (board_stack.top != STACK_EMPTY) {
        pop_board_stack(&board_stack, &board_candidate);

        if (!find_board_blank(&board_candidate, &x, &y)) {
            *initial_board = board_candidate;
            return true;
        }

        for (int possible_value = 9; possible_value >= 1; --possible_value) {
            set_board_value(&board_candidate, x, y, possible_value);
            if (!validate_board(&board_candidate, x, y)) continue;
            new_board_candidate = copy_board(&board_candidate, arena);
            push_board_stack(&board_stack, &new_board_candidate);
        }
    }
    return false;
}
