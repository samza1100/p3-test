#include "songentry.h"
#include <QVBoxLayout>

SongEntry::SongEntry(const QString &songName, const QString &artistName, QWidget *parent)
    : QWidget(parent) {

    // Create a vertical box layout to stack song and artist labels
    QVBoxLayout *layout = new QVBoxLayout(this);
    // Create the song label with the song name
    QLabel *songLabel = new QLabel(songName, this);
    // Create the artist label with the artist name
    QLabel *artistLabel = new QLabel(artistName, this);

    // Set the font for the song label to Century Gothic, size 18
    QFont songFont("Century Gothic", 18);
    songLabel->setFont(songFont);
    // Set the text color of the song label to white
    songLabel->setStyleSheet("QLabel { ""color: white; ""}");

    // Set the font for the artist label to Century Gothic, size 16
    QFont artishFont("Century Gothic", 16);
    artistLabel->setFont(artishFont);
    // Set the text color of the artist label to grey
    artistLabel->setStyleSheet("QLabel { ""color: grey; ""}");

    // Add the song and artist labels to the layout
    layout->addWidget(songLabel);
    layout->addWidget(artistLabel);
}
