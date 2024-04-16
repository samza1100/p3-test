#ifndef SONGENTRY_H
#define SONGENTRY_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>

class SongEntry : public QWidget {
    Q_OBJECT

public:
   explicit SongEntry(const QString &songName, const QString &artistName, QWidget *parent = nullptr);
};

#endif // SONGENTRY_H
