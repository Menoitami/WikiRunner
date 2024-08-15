#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    this->resize(QSize(1024,768));

    QFile file("../../LocalSettings/Person.json");

    if (!file.open(QIODevice::ReadOnly)) {
        qWarning("Couldn't open file.");
        return;
    }

    QByteArray fileData = file.readAll();
    file.close();
    QJsonDocument doc(QJsonDocument::fromJson(fileData));
    person = std::make_shared<PersonClass>(doc);


    regWindow = new RegWindow(this, person);
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
    if (person){
        person = nullptr;

    }


}




