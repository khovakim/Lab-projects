#include "settings.h"
#include "ui_settings.h"
#include "QMessageBox"

Settings::Settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Settings),
    teams(new Teams())
{
    ui->setupUi(this);

    connect(teams, &Teams::back, this, &Settings::show);
}

Settings::~Settings()
{
    delete ui;
    delete teams;
}

void Settings::on_pushButtonBack_clicked()
{
    this->close();
    emit back();
}

void Settings::CreateTeams()
{
    teams->labels = new QLabel[teams->teamNumber] ();
    teams->lineEdit = new QLineEdit[teams->teamNumber] ();

    for (int i = 0; i < teams->teamNumber; ++i){
        teams->labels[i].setText("Team" + QString::number(i + 1));
        teams->labels[i].setStyleSheet("color: rgb(242, 232, 27)");
        teams->lineEdit[i].setStyleSheet("background-color:rgb(250, 255, 0)");
    }
    teams->layout = new QFormLayout(teams);
    for (int i = 0; i < teams->teamNumber; ++i) {
        teams->layout->addRow(&teams->labels[i], &teams->lineEdit[i]);
    }
    this->close();
    teams->show();
}

void Settings::on_pushButtonNext_clicked()
{
    teams->teamNumber = ui->teamCount->text().toInt();
    teams->timeNumber = ui->roundTime->text().toInt();
    teams->pointNumber = ui->winningPointCount->text().toInt();

    if (teams->teamNumber < 2 || teams->teamNumber > 6) {
        QMessageBox::warning(this, "warning",
                     "Count of teams must be greater than 1 and less than 6");
        return ;
    } else if (teams->timeNumber < 30 || teams->timeNumber > 120) {
        QMessageBox::warning(this, "warning",
                     "Time must be between 30 and 120 seconds");
        return ;
    } else if (teams->pointNumber < 50 || teams->pointNumber > 100) {
        QMessageBox::warning(this, "warning",
                     "Winning points must be between 50 and 100 seconds");
        return ;
    } else {
        CreateTeams();
    }
}

