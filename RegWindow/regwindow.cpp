#include "regwindow.h"
#include "ui_regwindow.h"

RegWindow::RegWindow(QWidget *parent, std::shared_ptr<PersonClass> person)
    : QWidget(parent)
    , ui(new Ui::RegWindow)
{

    this->person= person;

    ui->setupUi(this);

    ui->nickEdit->setText(person->getName());

    QString imagePath = person->getImage();


    QFileInfo checkFile(imagePath);
    if (checkFile.exists() && checkFile.isFile()) {
        QPixmap pixmap(imagePath);

        ui->pictureLabel->setPixmap(pixmap.scaled(150, 150));
    } else {
        qWarning() << "File does not exist or is not a file:" << imagePath;
    }

}

RegWindow::~RegWindow()
{
    delete ui;

    if (person){
        person = nullptr;

    }

}





void RegWindow::on_changePicButton_clicked()
{

    QString fileName = QFileDialog::getOpenFileName(this,
                                            tr("Open Image"), "./", tr("Image Files (*.png *.jpg *.bmp)"));

    ui->pictureLabel->setPixmap(QPixmap(fileName).scaled(150,150));
}




