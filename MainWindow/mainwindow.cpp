#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), currentWid(nullptr), createWindow(nullptr), regWindow(nullptr)
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

    openWindow(regWindow);
    regWindow->setPerson(person);
    connect(regWindow, &RegWindow::createTheRoom_sig,this, &MainWindow::openCreateRoomWind);
}


void MainWindow::openCreateRoomWind(){

    openWindow(createWindow);

}


template <QWidgetDerived T>
void MainWindow::openWindow(T*& window) {
    if (currentWid) {
        currentWid->hide();
    }

    if (!window) {
        window = new T(this);
    }

    currentWid = window;
    setCentralWidget(window);
    currentWid->show();
}

MainWindow::~MainWindow()
{
    delete ui;
    if (regWindow) {
        delete regWindow;
    }
    if (person){
        person = nullptr;

    }
    if (createWindow){
        delete createWindow;

    }


}




