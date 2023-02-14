#ifndef DATABASE_H
#define DATABASE_H

#include <QDialog>

namespace Ui {
class DataBase;
}

class DataBase : public QDialog
{
    Q_OBJECT

public:
    explicit DataBase(QWidget *parent = nullptr);
    ~DataBase();

private slots:
    void on_pushButtonAppend_clicked();

private:
    Ui::DataBase *ui;
};

#endif // DATABASE_H
