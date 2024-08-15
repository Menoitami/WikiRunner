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
    explicit RegWindow(QWidget *parent = nullptr);
    ~RegWindow();



private slots:



    void on_changePicButton_clicked();

signals:

    void sendPersonToMainWindow();

private:
    Ui::RegWindow *ui;
};

#endif // REGWINDOW_H
