#include "regwindow.h"
#include "ui_regwindow.h"

RegWindow::RegWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RegWindow)
{



    ui->setupUi(this);


}

void RegWindow::setPerson(std::shared_ptr<PersonClass> person){

    this->person= person;

    ui->nickEdit->setText(person->getName());

    QString imagePath = person->getImage();


    QFileInfo checkFile(imagePath);
    if (checkFile.exists() && checkFile.isFile()) {

        ui->pictureLabel->setPixmap( QPixmap(imagePath).scaled(150, 150));

    } else {

        setRandomPic();

    }



}

void RegWindow::setRandomPic(){

    unsigned short int randomNumber = QRandomGenerator::global()->bounded(1, 4);
    QString imagePath = QString(":/PersonLogo/LocalSettings/Pictures/logos/%1.jpeg").arg(randomNumber);
    ui->pictureLabel->setPixmap( QPixmap(imagePath).scaled(150, 150));

}

void RegWindow::on_changePicButton_clicked()
{

    QString fileName = QFileDialog::getOpenFileName(this,
                                            tr("Open Image"), "./", tr("Image Files (*.png *.jpg *.bmp *.jpeg)"));


    person->setImage(fileName);
    if(fileName.isEmpty()){

        setRandomPic();
        return;

    }



    ui->pictureLabel->setPixmap(QPixmap(fileName).scaled(150,150));
}


void RegWindow::on_nickEdit_textChanged(const QString &arg1)
{
    QString name = arg1;
    person->setName(name);

}


void RegWindow::on_createButton_clicked()
{
    emit createTheRoom_sig();
}

RegWindow::~RegWindow()
{
    delete ui;

    if (person){
        person = nullptr;

    }

}






