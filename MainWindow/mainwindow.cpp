#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    this->resize(QSize(1024,768));

    regWindow = new RegWindow(this);
     connect(regWindow, &RegWindow::login_sig, this, &MainWindow::openMenu);



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


void MainWindow::openMenu(){


    currentWid->hide();

    currentWid = menuWindow;

    currentWid->show();

}

