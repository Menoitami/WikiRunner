#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    this->resize(QSize(1024,768));

    regwindow = new RegWindow(this);
    currentWid = regwindow;

    setCentralWidget(regwindow);
}

MainWindow::~MainWindow()
{
    delete ui;
    if (regwindow) {
        delete regwindow;
    }
}


