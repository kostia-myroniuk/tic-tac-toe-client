#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <algorithm>

#include "cell.h"

const int MIN_BOARD_SIZE = 3;
const int MAX_BOARD_SIZE = 10;

class Board
{
public:
    Board(int _size, std::vector<Cell*> _cells);
    int GetSize();
    std::vector<Cell*> GetCells();
    Cell* GetCell(int row, int column);

private:
    int size;
    std::vector<Cell*> cells;
};

#endif // BOARD_H
