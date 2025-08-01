#pragma once
#include <QMainWindow>
#include <QMap>
#include <QString>
QT_BEGIN_NAMESPACE
namespace Ui {
class Messages;
}
QT_END_NAMESPACE

class Messages : public QMainWindow
{
    Q_OBJECT

public:
    Messages(QWidget *parent = nullptr);
    ~Messages();

private:
    void SetConnections();


    QMap<QString, QString> answers_;
    Ui::Messages *ui;

};
