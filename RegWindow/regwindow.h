#ifndef REGWINDOW_H
#define REGWINDOW_H

#include <QWidget>
#include <QFileDialog>
#include <QFile>
#include <QJsonDocument>
#include <QByteArray>
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
    
signals:


private:
    Ui::RegWindow *ui;
    std::shared_ptr<PersonClass> person;


};

#endif // REGWINDOW_H
