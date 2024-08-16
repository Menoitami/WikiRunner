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
    explicit RegWindow(QWidget *parent = nullptr, std::shared_ptr<PersonClass> person = nullptr);
    ~RegWindow();



private slots:

    void on_changePicButton_clicked();
    
    void on_nickEdit_textChanged(const QString &arg1);

signals:


private:
    Ui::RegWindow *ui;
    std::shared_ptr<PersonClass> person;


    void setRandomPic();


};

#endif // REGWINDOW_H
