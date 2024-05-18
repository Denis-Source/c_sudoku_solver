cmake_minimum_required(VERSION 3.16)
project(sudoku_solver C)

set(CMAKE_C_STANDARD 11)

add_executable(sudoku_solver main.c stack/stack.c stack/stack.h board/board.c board/board.h solver.c solver.h misc/misc.c misc/misc.h tests/suite.c tests/suite.h tests/test_stack.c tests/test_stack.h tests/test_board.c tests/test_board.h tests/mocks.h tests/mocks.c tests/test_solver.c tests/test_solver.h arena/arena.c arena/arena.h)