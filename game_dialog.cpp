#include "game_dialog.h"
#include "./ui_game_dialog.h"

GameDialog::GameDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::GameDialog)
{
    ui->setupUi(this);
}

GameDialog::~GameDialog()
{
    delete ui;
}

