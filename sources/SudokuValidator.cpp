#include <SudokuValidator/SudokuValidator.h>

#include <iostream>

namespace
{

bool ValidateSudokuCells(const std::array<std::array<uint8_t, 9>, 9>& sudoku)
{
    for (uint8_t i = 0; i < 9; ++i)
    {
        for (uint8_t j = 0; j < 9; ++j)
        {
            if (sudoku[i][j] > 9)
            {
                return false;
            }
        }
    }
    return true;
}

bool ValidateRepeatedItems(const uint8_t cell_value, uint16_t& bit_mask)
{
    const auto bit_value = static_cast<uint16_t>(1) << (cell_value - 1);
    if ((bit_value & bit_mask) != 0)
    {
        return false;
    }
    bit_mask |= bit_value;
    return true;
}

} // namespace

bool ValidateSudoku(const std::array<std::array<uint8_t, 9>, 9>& sudoku)
{
    if (!ValidateSudokuCells(sudoku))
    {
        return false;
    }

    uint16_t h_bit_mask = 0;
    uint16_t v_bit_mask = 0;
    uint16_t b_bit_mask = 0;


    for (uint8_t i = 0; i < 9; ++i)
    {
        for (uint8_t j = 0; j < 9; ++j)
        {
            if (!ValidateRepeatedItems(sudoku[i][j], h_bit_mask))
            {
                std::cout << "h = " << static_cast<int>(i) << " " << static_cast<int>(j) << std::endl;
                return false;
            }
            if (!ValidateRepeatedItems(sudoku[j][i], v_bit_mask))
            {
                std::cout << "v = " << static_cast<int>(j) << " " << static_cast<int>(i) << std::endl;
                return false;
            }
            if (!ValidateRepeatedItems(sudoku[(i / 3) * 3 + j / 3][(i % 3) * 3 + j % 3], b_bit_mask))
            {
                std::cout << "b = " << static_cast<int>(i / 3) << " " << static_cast<int>(j % 3) << std::endl;
                return false;
            }
        }
        h_bit_mask = 0;
        v_bit_mask = 0;
        b_bit_mask = 0;
    }
    return true;
}