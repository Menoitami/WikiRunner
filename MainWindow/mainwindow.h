#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRect>
#include <concepts>
#include "regwindow.h"
#include "personclass.h"
#include "createroomwindow.h"

template <typename T>
concept QWidgetDerived = std::is_base_of<QWidget, T>::value;

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
    void openCreateRoomWind();

signals:


private:
    Ui::MainWindow *ui;
    RegWindow* regWindow;
    CreateRoomWindow* createWindow;
    QWidget* currentWid;
    std::shared_ptr<PersonClass> person;

    template <QWidgetDerived T>
    void openWindow(T*& window);

};

#endif // MAINWINDOW_H
