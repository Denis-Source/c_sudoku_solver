#include <assert.h>
#include <time.h>
#include "test_solver.h"
#include "../stack/stack.h"
#include "mocks.h"
#include "../solver.h"
#include "../misc/misc.h"
#include "stdio.h"
#include "../arena/arena.h"

void test_solver_board_easy() {
    Arena arena = initialize_arena(BOARD_MEM_SIZE * 1e6);
    Board board = initialize_board(easy_board_field, &arena);

    printf("Measuring easy board\n");
    clock_t begin = clock();

    bool solved = solve_board(&board, &arena);
    assert(solved);
    for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; ++i) {
        assert(board._field[i] == easy_board_solution[i]);
    }
    print_time_spent(begin);
    free_arena(&arena);
}

void test_solver_board_medium() {
    Arena arena = initialize_arena(BOARD_MEM_SIZE * 1e6);
    Board board = initialize_board(medium_board_field, &arena);

    printf("Measuring medium board\n");
    clock_t begin = clock();

    bool solved = solve_board(&board, &arena);
    assert(solved);
    for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; ++i) {
        assert(board._field[i] == medium_board_solution[i]);
    }
    print_time_spent(begin);
    free_arena(&arena);
}

void test_solver_board_hard() {
    Arena arena = initialize_arena(BOARD_MEM_SIZE * 1e6);
    Board board = initialize_board(hard_board_field, &arena);

    printf("Measuring hard board\n");
    clock_t begin = clock();

    bool solved = solve_board(&board, &arena);
    assert(solved);
    for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; ++i) {
        assert(board._field[i] == hard_board_solution[i]);
    }
    print_time_spent(begin);
    free_arena(&arena);
}

void test_solver_board_hardest() {
    Arena arena = initialize_arena(BOARD_MEM_SIZE * 1e6);
    Board board = initialize_board(hardest_board_field, &arena);

    printf("Measuring hardest board\n");
    clock_t begin = clock();

    bool solved = solve_board(&board, &arena);
    assert(solved);
    for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; ++i) {
        assert(board._field[i] == hardest_board_solution[i]);
    }
    print_time_spent(begin);
    free_arena(&arena);
}


void run_solver_test(void) {
    test_solver_board_easy();
    test_solver_board_medium();
    test_solver_board_hard();
    test_solver_board_hardest();
}