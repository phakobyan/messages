#pragma once
#include <QMainWindow>

namespace Ui {
class FirstWindow;
}

class FirstWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit FirstWindow(QWidget *parent = nullptr);
    ~FirstWindow();

private:
    Ui::FirstWindow *ui;
    void MenuButtons();
};

