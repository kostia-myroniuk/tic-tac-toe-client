#include "board.h"

Board::Board(int _size, std::vector<Cell *> _cells)
{
    size = std::clamp(_size, MIN_BOARD_SIZE, MAX_BOARD_SIZE);
    cells = _cells;
}

int Board::GetSize()
{
    return size;
}

std::vector<Cell *> Board::GetCells()
{
    return cells;
}

Cell *Board::GetCell(int row, int column)
{
    if (row > 0 && row < size && column > 0 && column < size) {
        return cells[row * size + column];
    }
    else {
        return nullptr;
    }
}
