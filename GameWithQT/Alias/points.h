#ifndef POINTS_H
#define POINTS_H

#include <QWidget>
#include "game.h"
#include "teams.h"
#include <QLabel>
#include <QFormLayout>
#include <QPushButton>

namespace Ui {
class Points;
}

class Points : public QWidget
{
    Q_OBJECT

public:
    explicit Points(QWidget *parent = nullptr, int teamNumber = 0,
                    int timeNumber = 0, int pointNumber = 0,
                    QLineEdit *names = nullptr);
    ~Points();

public:
    QLabel *name;
    QLabel *points;
    QFormLayout *layout;

private slots:
    void on_pushButtonPlay_clicked();

private:
    Ui::Points *ui;
    QString *mnames;
    int counter;
    int mteamNumber;
    int mtimeNumber;
    int mpointNumber;
    int mindex;
    Game *game;

};

#endif // POINTS_H
