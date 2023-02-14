#include "game.h"
#include "ui_game.h"
#include <QFile>
#include <QDebug>
#include <QRandomGenerator>

Game::Game(QWidget *parent, int timeNumber, int* counter) :
    QDialog(parent),
    ui(new Ui::Game),
    mtimeNumber(timeNumber),
    mcount(counter)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(generateSeconds()));

    QFile fileName("../Alias/database.txt");
    if (!fileName.exists()) {
        qDebug() << "no such file";
        return ;
    }
    if (!fileName.open(QFile::ReadOnly | QFile::Text)) {
        qDebug() << " Could not open file";
        return ;
    }
    while (!fileName.atEnd()) {
        words.push_back(fileName.readLine());
    }
    ui->pointCount->setText(QString::number(*mcount));
}

void Game::generateWords()
{
    ui->currentWord->setText(words[((qrand() % words.size()) * 100) % words.size()]);
}

void Game::generateSeconds()
{
    static int i = mtimeNumber;
    ui->timer->setText(QString::number(i--));
    if (i == 0) {
        timer->stop();
        i = mtimeNumber;
        ui->pointCount->setText(QString::number(0));
        this->close();
        emit back();
    }
}

Game::~Game()
{
    delete ui;
}

void Game::on_pushButtonPlus_clicked()
{
    (*mcount)++;
    generateWords();
    ui->pointCount->setText(QString::number(*mcount));
}


void Game::on_pushButtonMinus_clicked()
{
    (*mcount)--;
    generateWords();
    ui->pointCount->setText(QString::number(*mcount));
}

