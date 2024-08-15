#include "regwindow.h"
#include "ui_regwindow.h"

RegWindow::RegWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RegWindow)
{
    ui->setupUi(this);

    QFile file("../../LocalSettings/Person.json");
    qDebug()<<file.fileName();

    if (!file.open(QIODevice::ReadOnly)) {
        qWarning("Couldn't open file.");
        return;
    }

    QByteArray fileData = file.readAll();
    file.close();

    QJsonDocument doc(QJsonDocument::fromJson(fileData));

    PersonClass person(doc);


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

