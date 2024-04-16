#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "resultwin.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->goButton, SIGNAL(clicked()), this, SLOT(on_goButton_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_goButton_clicked()
{
    this->hide();
    auto resultWindow = new resultWin();
    resultWindow->setAttribute(Qt::WA_DeleteOnClose);
    resultWindow->show();


}

