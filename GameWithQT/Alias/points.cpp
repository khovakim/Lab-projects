#include "points.h"
#include "ui_points.h"
#include <QDebug>
#include <QMessageBox>
#include <QSignalMapper>

Points::Points(QWidget *parent, int teamNumber,
               int timeNumber, int pointNumber,
               QLineEdit *names) :
                QWidget(parent),
                ui(new Ui::Points),
                counter(0),
                mteamNumber(teamNumber),
                mtimeNumber(timeNumber),
                mpointNumber(pointNumber),
                mindex(-1),
                game(new Game(nullptr, mtimeNumber, &counter))

{
    ui->setupUi(this);
    mnames = new QString [mteamNumber] ();
    for (int i = 0; i < mteamNumber; ++i) {
        mnames[i] = names[i].text();
    }
    this->name = new QLabel[mteamNumber] ();
    this->points = new QLabel[mteamNumber] ();
    for (int i = 0; i < teamNumber; ++i){
        name[i].setText(mnames[i]);
        name[i].setStyleSheet("color: rgb(242, 232, 27);\
                                       font-size: 40px;\
                                       padding-top: 30px;");
        points[i].setText("0");
        points[i].setStyleSheet("color: rgb(242, 232, 27);\
                                        font-size: 40px;\
                                        padding-top: 30px;");
    }
    this->layout = new QFormLayout(this);
    for (int i = 0; i < teamNumber; ++i) {
        this->layout->addRow(&name[i], &points[i]);
    }

    connect(game, &Game::back, this, [&]() {
        points[mindex].setText(
                    QString::number(points[mindex].text().toInt()
                                    + counter)
                    );
        counter = 0;
        this->show();
        for (int i = 0; i < mteamNumber; ++i) {
                if (points[i].text().toInt() >= mpointNumber) {
                    QMessageBox::information(this, "End Game", name[i].text() + " Won !!!");
                    exit(0);
                }
            }
    });
}

Points::~Points()
{
    delete ui;
}

void Points::on_pushButtonPlay_clicked()
{
    this->close();
    game->timer->start(1000);
    game->generateWords();
    game->show();

    ++mindex;
    if (mindex == mteamNumber) {
        mindex = 0;
    }
}




