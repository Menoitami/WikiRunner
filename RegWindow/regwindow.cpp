#include "regwindow.h"
#include "ui_regwindow.h"

RegWindow::RegWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RegWindow)
{
    ui->setupUi(this);
}

RegWindow::~RegWindow()
{
    delete ui;
}





void RegWindow::on_changePicButton_clicked()
{

   QString fileName = QFileDialog::getOpenFileName(this,
                                            tr("Open Image"), "./", tr("Image Files (*.png *.jpg *.bmp)"));




   ui->pictureLabel->setPixmap(QPixmap(fileName).scaled(QSize(150,150)));

}

