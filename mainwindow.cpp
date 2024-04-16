#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "resultwin.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_goButton_clicked()
{
    /*if(ui->song1->text().trimmed().isEmpty() ||
        ui->song2->text().trimmed().isEmpty() ||
        ui->song3->text().trimmed().isEmpty())
    {
        // If any box is empty, show a message box to the user
        QMessageBox::warning(this,"Not Enough Songs", "Please Pick 3 Songs");
        return;
    }*/

    this->hide();
    auto resultWindow = new resultWin();
    resultWindow->setAttribute(Qt::WA_DeleteOnClose);
    resultWindow->show();


}

