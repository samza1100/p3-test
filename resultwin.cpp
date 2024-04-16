#include "resultwin.h"
#include "ui_resultwin.h"
#include <QApplication>

resultWin::resultWin(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::resultWin)
{
    ui->setupUi(this);
}

resultWin::~resultWin()
{
    delete ui;
}
