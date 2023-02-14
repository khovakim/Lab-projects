#ifndef TEAMS_H
#define TEAMS_H

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QFormLayout>

namespace Ui {
class Teams;
}

class Teams : public QWidget
{
    Q_OBJECT

public:
    explicit Teams(QWidget *parent = nullptr);
    ~Teams();

    void CreatePointsWindow();
signals:
    void back();

public:
    int teamNumber;
    int timeNumber;
    int pointNumber;
    QLabel *labels;
    QLineEdit *lineEdit;
    QFormLayout *layout;

private slots:
    void on_pushButtonBack_clicked();

    void on_pushButtonNext_clicked();

private:
    Ui::Teams *ui;
};

#endif // TEAMS_H
