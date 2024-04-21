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
    QStringList artists;
    artists << ui->box1->text().trimmed()
          << ui->box2->text().trimmed()
          << ui->box3->text().trimmed();

    if (artists.contains("")) {
        // If any box is empty, show a message box to the user
        QMessageBox::warning(this,"Not Enough Data", "Please Choose 3 Artists");
        return;
    }

    this->hide();
    auto resultWindow = new resultWin();
    resultWindow->setAttribute(Qt::WA_DeleteOnClose);
    resultWindow->show();


}

