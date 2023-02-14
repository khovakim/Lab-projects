#include "database.h"
#include "ui_database.h"
#include "QDebug"
#include "QString"
#include "QMessageBox"
#include "QFile"
#include "QTextStream"
#include "QByteArray"
#include <QApplication>

DataBase::DataBase(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DataBase)
{
    ui->setupUi(this);
}

DataBase::~DataBase()
{
    delete ui;
}

void DataBase::on_pushButtonAppend_clicked()
{
    QString word = ui->word->text();
    //QFile fileName("/home/user/Desktop/GameWithQT/Alias/database.txt");
    QFile fileName("../Alias/database.txt");
    if (word.isEmpty()) {
        return ;
    }
    if (!fileName.exists()) {
        qDebug() << "no such file";
        return ;
    }
    if (!fileName.open(QFile::ReadOnly | QFile::WriteOnly | QFile::Text)) {
        qDebug() << " Could not open file";
        return ;
    }
    word += '\n';
    QString line;
    while (!fileName.atEnd()) {
        line = fileName.readLine();
        if (word == line) {
            QMessageBox::warning(this, "warning", "such a word existed");
            return ;
        }
    }
    QTextStream out(&fileName);
    out << word;
    fileName.flush();
    fileName.close();
    QMessageBox::information(this, "information", "the word successfully added");
}

