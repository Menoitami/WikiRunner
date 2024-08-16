#ifndef REGWINDOW_H
#define REGWINDOW_H

#include <QWidget>
#include <QFileDialog>
#include <QFile>
#include <QJsonDocument>
#include <QByteArray>
#include <QRandomGenerator>
#include <personclass.h>

namespace Ui {
class RegWindow;
}

class RegWindow : public QWidget
{
    Q_OBJECT

public:
    explicit RegWindow(QWidget *parent = nullptr);
    ~RegWindow();

    void setPerson(std::shared_ptr<PersonClass> person);



private slots:

    void on_changePicButton_clicked();
    
    void on_nickEdit_textChanged(const QString &arg1);

    void on_createButton_clicked();

signals:

    void createTheRoom_sig();

private:
    Ui::RegWindow *ui;
    std::shared_ptr<PersonClass> person;


    void setRandomPic();


};

#endif // REGWINDOW_H
