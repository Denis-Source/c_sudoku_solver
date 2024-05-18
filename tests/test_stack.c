#include "assert.h"
#include "test_stack.h"
#include "../stack/stack.h"
#include "mocks.h"

void test_initialize_board_stack_success(void) {
    BoardStack stack = initialize_board_stack(TEST_STACK_SIZE);

    assert(&stack != NULL); // Not correctly initialized in the memory
    assert(stack.size == TEST_STACK_SIZE); // Incorrect stack size
    assert(stack.top == STACK_EMPTY); // Incorrect stack address

    free_stack(&stack);
}

void test_push_stack_success(void) {
    BoardStack stack = initialize_board_stack(TEST_STACK_SIZE);
    Arena arena = initialize_arena(BOARD_MEM_SIZE);
    Board board = initialize_board(easy_board_field, &arena);

    bool success = push_board_stack(&stack, &board);

    assert (success); // Operation is not successful
    assert(stack.top == 0); // Incorrect address
    assert(stack._storage[0]._field == board._field); // Incorrect value

    free_stack(&stack);
    free_arena(&arena);
}

void test_push_stack_overflow(void) {
    BoardStack stack = initialize_board_stack(TEST_STACK_SIZE);
    Arena arena = initialize_arena(BOARD_MEM_SIZE * (TEST_STACK_SIZE + 1));


    for (int i = 0; i < TEST_STACK_SIZE; i++) {
        Board board = initialize_board(easy_board_field, &arena);
        push_board_stack(&stack, &board);
        free_arena(&arena);
    }

    Board board = initialize_board(easy_board_field, &arena);
    bool success = push_board_stack(&stack, &board);
    assert(!success); // Operation is unsuccessful
    assert(stack.top != TEST_STACK_SIZE); // Stack is moved
    assert(&stack._storage[TEST_STACK_SIZE] != &board); // Stack value changed

    free_stack(&stack);
    free_arena(&arena);
}

void test_pop_stack_success_first_value(void) {
    BoardStack stack = initialize_board_stack(TEST_STACK_SIZE);
    Arena arena = initialize_arena(BOARD_MEM_SIZE);
    Board board = initialize_board(easy_board_field, &arena);
    Board result;
    push_board_stack(&stack, &board);

    bool success = pop_board_stack(&stack, &result);

    assert(success); // Operation is not successful
    assert(result._field == board._field); // Result value is not as expected
    assert(stack.top == STACK_EMPTY); // Top address is not reset

    free_stack(&stack);
    free_arena(&arena);
}

void test_pop_stack_success_second_value(void) {
    BoardStack stack = initialize_board_stack(TEST_STACK_SIZE);

    Arena arena = initialize_arena(BOARD_MEM_SIZE * 2);

    Board board = initialize_board(easy_board_field, &arena);
    Board another_board = initialize_board(empty_board_field, &arena);
    Board result;

    push_board_stack(&stack, &board);
    push_board_stack(&stack, &another_board);

    bool success = pop_board_stack(&stack, &result);

    assert(success); // Operation is not successful
    assert(result._field == another_board._field); // Result value is not as expected
    assert(stack.top == 0); // Top address is not correct

    free_stack(&stack);
    free_arena(&arena);
}

void test_pop_stack_underflow(void) {
    BoardStack stack = initialize_board_stack(TEST_STACK_SIZE);
    Board result;

    bool success = pop_board_stack(&stack, &result);

    assert(!success); // Operation is not successful
    assert(stack.top == STACK_EMPTY); // Top address is initial

    free_stack(&stack);
}

void run_stack_tests(void) {
    test_initialize_board_stack_success();

    test_push_stack_success();
    test_push_stack_overflow();

    test_pop_stack_success_first_value();
    test_pop_stack_success_second_value();
    test_pop_stack_underflow();
}