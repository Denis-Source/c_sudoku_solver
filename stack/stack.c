#include "stack.h"
#include <stdlib.h>
#include <stdbool.h>


BoardStack initialize_board_stack(size_t size) {
    BoardStack *stack = (BoardStack *) malloc(sizeof(BoardStack));

    stack->top = STACK_EMPTY;
    stack->size = size;
    stack->_storage = (Board *) malloc(sizeof(Board) * size);

    if (stack == NULL) exit(-1);
    if (stack->_storage == NULL) exit(-1);

    return *stack;
}

bool push_board_stack(BoardStack *stack, Board *board) {
    if (stack->top >= stack->size - 1) return false; // Stack overflow

    stack->top++;
    stack->_storage[stack->top] = *board;
    return true;
}

bool pop_board_stack(BoardStack *stack, Board *result) {
    if (stack->top < 0) return false; // Stack underflow

    *result = stack->_storage[stack->top];
    stack->top--;
    return true;
}

void free_stack(BoardStack *stack) {
    free(stack->_storage);
    free(stack);
}
