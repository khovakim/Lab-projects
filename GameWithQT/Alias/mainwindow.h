#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "settings.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonRules_clicked();

    void on_pushButtonAddWord_clicked();

    void on_pushButtonPlay_clicked();

private:
    Ui::MainWindow *ui;
    Settings* msettingdWindow;
};
#endif // MAINWINDOW_H
