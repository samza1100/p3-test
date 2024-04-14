#ifndef RESULTWIN_H
#define RESULTWIN_H

#include <QWidget>

namespace Ui {
class resultWin;
}

class resultWin : public QWidget
{
    Q_OBJECT

public:
    explicit resultWin(QWidget *parent = nullptr);
    ~resultWin();

private:
    Ui::resultWin *ui;
};

#endif // RESULTWIN_H
