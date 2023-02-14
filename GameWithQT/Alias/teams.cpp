#include "teams.h"
#include "ui_teams.h"
#include "QMessageBox"
#include "points.h"

Teams::Teams(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Teams)
{
    ui->setupUi(this);
}

Teams::~Teams()
{
    delete ui;
}


void Teams::on_pushButtonBack_clicked()
{
    this->close();
    delete [] labels;
    delete [] lineEdit;
    delete layout;
    emit back();
}

void Teams::CreatePointsWindow()
{
    Points *points = new Points(nullptr, teamNumber, timeNumber,
                                pointNumber, lineEdit);

    this->close();
    points->show();
}

void Teams::on_pushButtonNext_clicked()
{
    for (int i = 0; i < teamNumber; ++i) {
        if (lineEdit[i].text().isEmpty()) {
            QMessageBox::warning(this, "warning", "Empty Team"
                                 + QString::number(i + 1)
                                 +" name. Please, enter name for every team");
            return ;
        }
    }
    CreatePointsWindow();
    delete [] labels;
    delete [] lineEdit;
    delete layout;
}

