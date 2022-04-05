#ifndef GAMEDIALOG_H
#define GAMEDIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class GameDialog; }
QT_END_NAMESPACE

class GameDialog : public QDialog
{
    Q_OBJECT

public:
    GameDialog(QWidget *parent = nullptr);
    ~GameDialog();

private:
    Ui::GameDialog *ui;
};
#endif // GAMEDIALOG_H
