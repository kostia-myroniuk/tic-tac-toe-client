#ifndef CELL_H
#define CELL_H

#include <QPushButton>

class Cell
{
public:
    Cell(int _row, int _column, QPushButton* _button);
    int GetRow();
    int GetColumn();
    QPushButton* GetButton();

private:
    int row;
    int column;
    QPushButton* button;
};

#endif // CELL_H
