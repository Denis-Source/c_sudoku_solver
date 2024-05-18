#include <stddef.h>


#ifndef SUDOKU_SOLVER_ARENA_H
#define SUDOKU_SOLVER_ARENA_H

typedef struct {
    size_t size;
    size_t used;
    void *memory;
} Arena;

Arena initialize_arena(size_t size);

void free_arena(Arena *arena);

void *alloc_arena(Arena *arena, size_t size);

#endif //SUDOKU_SOLVER_ARENA_H
