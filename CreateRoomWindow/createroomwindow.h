#ifndef CREATEROOMWINDOW_H
#define CREATEROOMWINDOW_H

#include <QWidget>

namespace Ui {
class CreateRoomWindow;
}

class CreateRoomWindow : public QWidget
{
    Q_OBJECT

public:
    explicit CreateRoomWindow(QWidget *parent = nullptr);
    ~CreateRoomWindow();

private:
    Ui::CreateRoomWindow *ui;
};

#endif // CREATEROOMWINDOW_H
