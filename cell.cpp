#include "cell.h"

Cell::Cell(int _row, int _column, QPushButton *_button)
{
    row = _row;
    column = _column;
    button = _button;
}

int Cell::GetRow()
{
    return row;
}

int Cell::GetColumn()
{
    return column;
}

QPushButton *Cell::GetButton()
{
    return button;
}
