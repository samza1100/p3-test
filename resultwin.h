#ifndef RESULTWIN_H
#define RESULTWIN_H

#include <QWidget>
#include "ui_resultwin.h"
#include <QVBoxLayout>
#include <QLabel>

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
    void populateScrollAreas();
};

#endif // RESULTWIN_H
