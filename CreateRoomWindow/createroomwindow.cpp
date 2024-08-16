#include "createroomwindow.h"
#include "ui_createroomwindow.h"

CreateRoomWindow::CreateRoomWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreateRoomWindow)
{
    ui->setupUi(this);
}

CreateRoomWindow::~CreateRoomWindow()
{
    delete ui;
}
