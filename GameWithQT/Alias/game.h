#ifndef GAME_H
#define GAME_H

#include <QDialog>
#include <QTimer>
#include <QVector>

namespace Ui {
class Game;
}

class Game : public QDialog
{
    Q_OBJECT

public:
    explicit Game(QWidget *parent = nullptr, int timeNumber = 0, int *counter = nullptr);
    ~Game();

    void generateWords();

signals:
    void back();
public slots:
    void generateSeconds();

private slots:
    void on_pushButtonPlus_clicked();

    void on_pushButtonMinus_clicked();

public:
    QTimer *timer;
private:
    Ui::Game *ui;
    QVector<QString> words;
    int mtimeNumber;
    int *mcount;


};

#endif // GAME_H
