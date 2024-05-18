#include "suite.h"
#include "stdio.h"
#include "test_stack.h"
#include "test_board.h"
#include "test_solver.h"

void run_tests(void) {
    run_stack_tests();
    printf("Stack tests finished with success!\n");

    run_board_tests();
    printf("Board tests finished with success!\n");

    run_solver_test();
    printf("Solver tests finished with success!\n");

    printf("All tests finished with success!\n");
}
