#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    this->resize(QSize(1024,768));

    regWindow = new RegWindow(this);
    setCentralWidget(regWindow);



    menuWindow = new MenuWindow(this);
    menuWindow->hide();



    currentWid = regWindow;
}

MainWindow::~MainWindow()
{
    delete ui;
    if (regWindow) {
        delete regWindow;
    }
    if (menuWindow) {
        delete menuWindow;
    }


}



