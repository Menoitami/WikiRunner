#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRect>
#include <QResizeEvent>
#include "regwindow.h"
#include "menuwindow.h"

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

    void openMenu();

private:
    Ui::MainWindow *ui;
    RegWindow* regWindow;
    MenuWindow* menuWindow;
    QWidget* currentWid;


};

#endif // MAINWINDOW_H
