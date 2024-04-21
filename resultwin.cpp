#include "resultwin.h"
#include "ui_resultwin.h"
#include "songentry.h"

using namespace std;


resultWin::resultWin(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::resultWin)
{
    ui->setupUi(this);
    populateScrollAreas();

}

resultWin::~resultWin()
{
    delete ui;
}

void resultWin::populateScrollAreas() {
    // Create a container widget for the first scroll area
    QWidget *container1 = new QWidget();
    // Set up a vertical box layout for this container
    QVBoxLayout *layout1 = new QVBoxLayout(container1);

    // Example loop for top 500 songs
    // Create and add SongEntry widgets to the layout for the "Top 500" songs
    for (int i = 0; i < 10; ++i) {
        // Create a new SongEntry with placeholder text
        SongEntry *entry = new SongEntry("Placeholder Song " + QString::number(i),
                                         "Placeholder Artist " + QString::number(i),
                                         container1);
        // Add the SongEntry to the layout
        layout1->addWidget(entry);
    }
    // Set the container as the scrollable content for the first scroll area
    ui->scrollArea->setWidget(container1);


    QWidget *container2 = new QWidget();
    QVBoxLayout *layout2 = new QVBoxLayout(container2);
    // Example loop for random songs
    for (int i = 0; i < 5; ++i) {
        SongEntry *entry = new SongEntry("Placeholder Song " + QString::number(i),
                                         "Placeholder Artist " + QString::number(i),
                                         container2);
        layout2->addWidget(entry);
    }
    ui->scrollArea2->setWidget(container2);
}
