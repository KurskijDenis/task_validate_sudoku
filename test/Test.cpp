#include <SudokuValidator/SudokuValidator.h>

#include <gtest/gtest.h>

#include <array>
#include <cstdint>


TEST(SudokuValidator, Test1)
{
    std::array<std::array<uint8_t, 9>, 9> sudoku{
        std::array<uint8_t, 9>{0, 1, 0, 4, 0, 3, 0, 8, 0},
        std::array<uint8_t, 9>{0, 5, 2, 1, 0, 7, 9, 0, 3},
        std::array<uint8_t, 9>{4, 9, 0, 2, 8, 0, 1, 0, 6},

        std::array<uint8_t, 9>{1, 0, 0, 0, 0, 0, 0, 0, 0},
        std::array<uint8_t, 9>{2, 3, 0, 6, 0, 1, 0, 9, 0},
        std::array<uint8_t, 9>{0, 0, 4, 0, 9, 0, 8, 0, 1},

        std::array<uint8_t, 9>{5, 0, 0, 0, 2, 0, 0, 0, 7},
        std::array<uint8_t, 9>{0, 4, 0, 0, 0, 0, 0, 2, 0},
        std::array<uint8_t, 9>{8, 0, 0, 0, 7, 0, 4, 0, 0},
    };
    EXPECT_TRUE(ValidateSudoku(sudoku));
}

TEST(SudokuValidator, Test2)
{
    std::array<std::array<uint8_t, 9>, 9> sudoku{
        std::array<uint8_t, 9>{0, 1, 0, 4, 0, 3, 0, 8, 0},
        std::array<uint8_t, 9>{0, 5, 2, 1, 0, 7, 9, 0, 3},
        std::array<uint8_t, 9>{4, 9, 0, 2, 8, 0, 1, 0, 6},

        std::array<uint8_t, 9>{1, 0, 0, 0, 0, 0, 0, 0, 0},
        std::array<uint8_t, 9>{2, 3, 0, 6, 0, 1, 0, 9, 0},
        std::array<uint8_t, 9>{0, 0, 4, 0, 9, 0, 8, 0, 1},

        std::array<uint8_t, 9>{5, 0, 0, 0, 2, 0, 0, 0, 7},
        std::array<uint8_t, 9>{1, 4, 0, 0, 0, 0, 0, 2, 0},
        std::array<uint8_t, 9>{8, 0, 0, 0, 7, 0, 4, 0, 0},
    };
    EXPECT_FALSE(ValidateSudoku(sudoku));
}

TEST(SudokuValidator, Test3)
{
    std::array<std::array<uint8_t, 9>, 9> sudoku{
        std::array<uint8_t, 9>{0, 1, 0, 4, 0, 3, 0, 3, 0},
        std::array<uint8_t, 9>{0, 5, 2, 1, 0, 7, 9, 0, 3},
        std::array<uint8_t, 9>{4, 9, 0, 2, 8, 0, 1, 0, 6},

        std::array<uint8_t, 9>{1, 0, 0, 0, 0, 0, 0, 0, 0},
        std::array<uint8_t, 9>{2, 3, 0, 6, 0, 1, 0, 9, 0},
        std::array<uint8_t, 9>{0, 0, 4, 0, 9, 0, 8, 0, 1},

        std::array<uint8_t, 9>{5, 0, 0, 0, 2, 0, 0, 0, 7},
        std::array<uint8_t, 9>{1, 4, 0, 0, 0, 0, 0, 2, 0},
        std::array<uint8_t, 9>{8, 0, 0, 0, 7, 0, 4, 0, 0},
    };
    EXPECT_FALSE(ValidateSudoku(sudoku));
}

TEST(SudokuValidator, Test4)
{
    std::array<std::array<uint8_t, 9>, 9> sudoku{
        std::array<uint8_t, 9>{0, 1, 0, 4, 0, 3, 0, 3, 0},
        std::array<uint8_t, 9>{0, 5, 2, 1, 0, 7, 9, 0, 3},
        std::array<uint8_t, 9>{4, 9, 0, 2, 8, 0, 1, 0, 6},

        std::array<uint8_t, 9>{1, 0, 0, 0, 6, 0, 0, 0, 0},
        std::array<uint8_t, 9>{2, 3, 0, 6, 0, 1, 0, 9, 0},
        std::array<uint8_t, 9>{0, 0, 4, 0, 9, 0, 8, 0, 1},

        std::array<uint8_t, 9>{5, 0, 0, 0, 2, 0, 0, 0, 7},
        std::array<uint8_t, 9>{1, 4, 0, 0, 0, 0, 0, 2, 0},
        std::array<uint8_t, 9>{8, 0, 0, 0, 7, 0, 4, 0, 0},
    };
    EXPECT_FALSE(ValidateSudoku(sudoku));
}