#include <assert.h>
#include "test_board.h"
#include "../board/board.h"
#include "stddef.h"
#include "mocks.h"


void test_initialize_board_success(void) {
    Board board = initialize_board(easy_board_field);

    assert(&board != NULL);
    for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; ++i) {
        assert(board._field[i] == easy_board_field[i]);
    }

    free_board(&board);
}

void test_access_board_success(void) {
    Board board = initialize_board(easy_board_field);
    int result = 0;
    int x = 4;
    int y = 2;

    bool success = access_board(&board, x, y, &result);
    assert(success);
    assert(result == board._field[y * BOARD_SIZE + x]);

    free_board(&board);
}

void test_access_board_out_of_bounds_x(void) {
    Board board = initialize_board(easy_board_field);
    int result = 0;
    int x = 42;
    int y = 2;

    bool success = access_board(&board, x, y, &result);
    assert(!success);
    assert(result == 0);

    free_board(&board);
}

void test_access_board_out_of_bounds_y(void) {
    Board board = initialize_board(easy_board_field);
    int result = 0;
    int x = 4;
    int y = 42;

    bool success = access_board(&board, x, y, &result);
    assert(!success);
    assert(result == 0);

    free_board(&board);
}

void test_set_board_value_success(void) {
    Board board = initialize_board(empty_board_field);
    int value = 9;
    int x = 4;
    int y = 2;

    bool success = set_board_value(&board, x, y, value);
    assert(success);
    assert(board._field[y * BOARD_SIZE + x] == value);
}

void test_set_board_out_value_of_bounds_x(void) {
    Board board = initialize_board(empty_board_field);
    int value = 9;
    int x = 42;
    int y = 4;

    bool success = set_board_value(&board, x, y, value);
    assert(!success);

    free_board(&board);
}

void test_set_board_value_out_of_bounds_y(void) {
    Board board = initialize_board(empty_board_field);
    int value = 9;
    int x = 4;
    int y = 42;

    bool success = set_board_value(&board, x, y, value);
    assert(!success);

    free_board(&board);
}

void test_find_blank_value_success(void) {
    int field[81] = {
            9, 8, 7, 6, 5, 4, 3, 2, 1,
            6, 5, 4, 3, 2, 1, 9, 8, 7,
            3, 2, 1, 9, 8, 7, 6, 5, 4,
            8, 9, 6, 7, 4, 5, 2, 1, 3,
            7, 4, 5, 2, 0, 3, 8, 9, 6,
            2, 1, 3, 8, 6, 9, 4, 7, 5,
            1, 6, 2, 5, 3, 8, 7, 4, 9,
            4, 3, 9, 1, 7, 2, 5, 6, 8,
            5, 7, 8, 4, 9, 6, 1, 3, 2,
    };
    Board board = initialize_board(field);
    int result_x, result_y;

    bool success = find_board_blank(&board, &result_x, &result_y);
    assert(success);
    assert(result_x == 4);
    assert(result_y == 4);

    free_board(&board);
}

void test_find_blank_value_no_blank(void) {
    int field[81] = {
            9, 8, 7, 6, 5, 4, 3, 2, 1,
            6, 5, 4, 3, 2, 1, 9, 8, 7,
            3, 2, 1, 9, 8, 7, 6, 5, 4,
            8, 9, 6, 7, 4, 5, 2, 1, 3,
            7, 4, 5, 2, 1, 3, 8, 9, 6,
            2, 1, 3, 8, 6, 9, 4, 7, 5,
            1, 6, 2, 5, 3, 8, 7, 4, 9,
            4, 3, 9, 1, 7, 2, 5, 6, 8,
            5, 7, 8, 4, 9, 6, 1, 3, 2,
    };
    Board board = initialize_board(field);
    int result_x, result_y;

    bool success = find_board_blank(&board, &result_x, &result_y);
    assert(!success);

    free_board(&board);
}

void test_validate_board_horizontal_valid(void) {
    int field[81] = {
            1, 2, 3, 4, 5, 6, 7, 8, 9, // <---
            0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0
    };
    Board board = initialize_board(field);
    int y = 0;

    bool success = validate_board_horizontal(&board, y);
    assert(success);

    free_board(&board);
}

void test_validate_board_horizontal_blank(void) {
    int field[81] = {
            1, 2, 3, 4, 5, 6, 7, 8, 0, // <---
            0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0
    };
    Board board = initialize_board(field);
    int y = 0;

    bool success = validate_board_horizontal(&board, y);
    assert(success);

    free_board(&board);
}

void test_validate_board_horizontal_not_valid(void) {
    int field[81] = {
            1, 2, 3, 4, 5, 6, 7, 8, 2, // <---
            0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0
    };
    Board board = initialize_board(field);
    int y = 0;

    bool success = validate_board_horizontal(&board, y);
    assert(!success);

    free_board(&board);
}


void test_validate_board_vertical_valid(void) {
    int field[81] = {
            //    |
            //    V
            0, 0, 1, 0, 0, 0, 0, 0, 0,
            0, 0, 2, 0, 0, 0, 0, 0, 0,
            0, 0, 3, 0, 0, 0, 0, 0, 0,
            0, 0, 4, 0, 0, 0, 0, 0, 0,
            0, 0, 5, 0, 0, 0, 0, 0, 0,
            0, 0, 6, 0, 0, 0, 0, 0, 0,
            0, 0, 7, 0, 0, 0, 0, 0, 0,
            0, 0, 8, 0, 0, 0, 0, 0, 0,
            0, 0, 9, 0, 0, 0, 0, 0, 0
    };
    Board board = initialize_board(field);
    int x = 2;

    bool success = validate_board_vertical(&board, x);
    assert(success);

    free_board(&board);
}

void test_validate_board_vertical_blank(void) {
    int field[81] = {
            //    |
            //    V
            0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 2, 0, 0, 0, 0, 0, 0,
            0, 0, 3, 0, 0, 0, 0, 0, 0,
            0, 0, 4, 0, 0, 0, 0, 0, 0,
            0, 0, 5, 0, 0, 0, 0, 0, 0,
            0, 0, 6, 0, 0, 0, 0, 0, 0,
            0, 0, 7, 0, 0, 0, 0, 0, 0,
            0, 0, 8, 0, 0, 0, 0, 0, 0,
            0, 0, 9, 0, 0, 0, 0, 0, 0
    };
    Board board = initialize_board(field);
    int x = 2;

    bool success = validate_board_vertical(&board, x);
    assert(success);

    free_board(&board);
}

void test_validate_board_vertical_not_valid(void) {
    int field[81] = {
            //    |
            //    V
            0, 0, 2, 0, 0, 0, 0, 0, 0,
            0, 0, 2, 0, 0, 0, 0, 0, 0,
            0, 0, 3, 0, 0, 0, 0, 0, 0,
            0, 0, 4, 0, 0, 0, 0, 0, 0,
            0, 0, 5, 0, 0, 0, 0, 0, 0,
            0, 0, 6, 0, 0, 0, 0, 0, 0,
            0, 0, 7, 0, 0, 0, 0, 0, 0,
            0, 0, 8, 0, 0, 0, 0, 0, 0,
            0, 0, 9, 0, 0, 0, 0, 0, 0
    };
    Board board = initialize_board(field);
    int x = 2;

    bool success = validate_board_vertical(&board, x);
    assert(!success);

    free_board(&board);
}

void test_validate_board_square_valid(void) {
    int field[81] = {
            //          |
            //          V
            0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 1, 2, 3, 0, 0, 0,
            0, 0, 0, 4, 5, 6, 0, 0, 0, // <--
            0, 0, 0, 7, 8, 9, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0
    };
    Board board = initialize_board(field);
    int x = 4;
    int y = 4;

    bool success = validate_board_square(&board, x, y);
    assert(success);

    free_board(&board);
}

void test_validate_board_square_blank(void) {
    int field[81] = {
            //          |
            //          V
            0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 1, 2, 3, 0, 0, 0,
            0, 0, 0, 4, 0, 6, 0, 0, 0, // <--
            0, 0, 0, 7, 8, 9, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0
    };
    Board board = initialize_board(field);
    int x = 4;
    int y = 4;

    bool success = validate_board_square(&board, x, y);
    assert(success);

    free_board(&board);
}


void test_validate_board_square_not_valid(void) {
    int field[81] = {
            //          |
            //          V
            0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 1, 2, 3, 0, 0, 0,
            0, 0, 0, 4, 1, 6, 0, 0, 0, // <--
            0, 0, 0, 7, 8, 9, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0
    };
    Board board = initialize_board(field);
    int x = 4;
    int y = 4;

    bool success = validate_board_square(&board, x, y);
    assert(!success);

    free_board(&board);
}

void test_validate_board_valid(void) {
    int field[81] = {
            //          |
            //          V
            9, 8, 7, 6, 5, 4, 3, 2, 1,
            6, 5, 4, 3, 2, 1, 9, 8, 7,
            3, 2, 1, 9, 8, 7, 6, 5, 4,
            8, 9, 6, 7, 4, 5, 2, 1, 3,
            7, 4, 5, 2, 1, 3, 8, 9, 6, // <--
            2, 1, 3, 8, 6, 9, 4, 7, 5,
            1, 6, 2, 5, 3, 8, 7, 4, 9,
            4, 3, 9, 1, 7, 2, 5, 6, 8,
            5, 7, 8, 4, 9, 6, 1, 3, 2,
    };

    Board board = initialize_board(field);

    int x = 4;
    int y = 4;

    bool success = validate_board(&board, x, y);
    assert(success);

    free_board(&board);
}

void test_validate_board_blank(void) {
    int field[81] = {
            //          |
            //          V
            9, 8, 7, 6, 5, 4, 3, 2, 1,
            6, 5, 4, 3, 2, 1, 9, 8, 7,
            3, 2, 1, 9, 8, 7, 6, 5, 4,
            8, 9, 6, 7, 4, 5, 2, 1, 3,
            7, 4, 5, 2, 0, 3, 8, 9, 6, // <--
            2, 1, 3, 8, 6, 9, 4, 7, 5,
            1, 6, 2, 5, 3, 8, 7, 4, 9,
            4, 3, 9, 1, 7, 2, 5, 6, 8,
            5, 7, 8, 4, 9, 6, 1, 3, 2,
    };

    Board board = initialize_board(field);

    int x = 4;
    int y = 4;

    bool success = validate_board(&board, x, y);
    assert(success);

    free_board(&board);
}

void test_validate_board_not_valid(void) {
    int field[81] = {
            //          |
            //          V
            9, 8, 7, 6, 5, 4, 3, 2, 1,
            6, 5, 4, 3, 2, 1, 9, 8, 7,
            3, 2, 1, 9, 8, 7, 6, 5, 4,
            8, 9, 6, 7, 4, 5, 2, 1, 3,
            7, 4, 5, 2, 2, 3, 8, 9, 6, // <--
            2, 1, 3, 8, 6, 9, 4, 7, 5,
            1, 6, 2, 5, 3, 8, 7, 4, 9,
            4, 3, 9, 1, 7, 2, 5, 6, 8,
            5, 7, 8, 4, 9, 6, 1, 3, 2,
    };

    Board board = initialize_board(field);

    int x = 4;
    int y = 0;

    bool success = validate_board(&board, x, y);
    assert(!success);

    free_board(&board);
}


void run_board_tests(void) {
    test_initialize_board_success();

    test_access_board_success();
    test_access_board_out_of_bounds_x();
    test_access_board_out_of_bounds_y();

    test_set_board_value_success();
    test_set_board_out_value_of_bounds_x();
    test_set_board_value_out_of_bounds_y();

    test_find_blank_value_success();
    test_find_blank_value_no_blank();

    test_validate_board_horizontal_valid();
    test_validate_board_horizontal_blank();
    test_validate_board_horizontal_not_valid();

    test_validate_board_vertical_valid();
    test_validate_board_vertical_blank();
    test_validate_board_vertical_not_valid();

    test_validate_board_square_valid();
    test_validate_board_square_blank();
    test_validate_board_square_not_valid();

    test_validate_board_valid();
    test_validate_board_blank();
    test_validate_board_not_valid();
}
