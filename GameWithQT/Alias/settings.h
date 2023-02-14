#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>
#include "teams.h"

namespace Ui {
class Settings;
}

class Settings : public QDialog
{
    Q_OBJECT

public:
    explicit Settings(QWidget *parent = nullptr);
    ~Settings();

    void CreateTeams();

private slots:
    void on_pushButtonBack_clicked();

    void on_pushButtonNext_clicked();

signals:
    void back();

private:
    Ui::Settings *ui;
    Teams *teams;

};

#endif // SETTINGS_H
