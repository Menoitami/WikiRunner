#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRect>
#include "regwindow.h"
#include "menuwindow.h"
#include "personclass.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:


signals:


private:
    Ui::MainWindow *ui;
    RegWindow* regWindow;
    MenuWindow* menuWindow;
    QWidget* currentWid;
    std::shared_ptr<PersonClass> person;

};

#endif // MAINWINDOW_H
