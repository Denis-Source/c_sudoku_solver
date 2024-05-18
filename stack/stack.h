#include <stdlib.h>
#include <stdbool.h>
#include "../board/board.h"

#ifndef TEST_STACK_H
#define TEST_STACK_H

#define STACK_EMPTY -1

typedef struct {
    int size;
    int top;
    Board *_storage;
} BoardStack;

BoardStack initialize_board_stack(size_t size);

bool push_board_stack(BoardStack *stack, Board *board);

bool pop_board_stack(BoardStack *stack, Board *result);

void free_stack(BoardStack *stack);

#endif
