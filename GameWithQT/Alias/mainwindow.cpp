#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "database.h"
#include "rules.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    msettingdWindow = new Settings();

    connect(msettingdWindow, &Settings::back, this, &MainWindow::show);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete msettingdWindow;
}


void MainWindow::on_pushButtonRules_clicked()
{
    Rules rulse;
    rulse.setModal(true);
    rulse.exec();
}


void MainWindow::on_pushButtonAddWord_clicked()
{
    DataBase data;
    data.setModal(true);
    data.exec();
}




void MainWindow::on_pushButtonPlay_clicked()
{
    this->close();
    msettingdWindow->show();
}

