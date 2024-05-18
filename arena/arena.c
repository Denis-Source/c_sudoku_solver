#include "arena.h"
#include <stdlib.h>


Arena initialize_arena(size_t size) {
    Arena *arena = (Arena *) malloc(sizeof(Arena));
    if (arena == NULL) exit(-1);

    arena->size = size;
    arena->used = 0;
    arena->memory = malloc(size);

    if (arena == NULL) exit(-1);

    return *arena;
}

void free_arena(Arena *arena) {
    free(arena->memory);
}

void *alloc_arena(Arena *arena, size_t size) {
    if (arena->used + size > arena->size) return NULL;

    void *ptr = (char *) arena->memory + arena->used;
    arena->used += size;
    return ptr;
}
