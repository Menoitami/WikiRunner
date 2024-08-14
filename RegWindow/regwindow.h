#ifndef REGWINDOW_H
#define REGWINDOW_H

#include <QWidget>

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
    void on_LogInButton_clicked();


signals:

    void login_sig();

private:
    Ui::RegWindow *ui;
};

#endif // REGWINDOW_H
