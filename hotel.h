#pragma once
#include <QMainWindow>
#include <QMap>
#include <QString>
QT_BEGIN_NAMESPACE
namespace Ui {
class Hotel;
}
QT_END_NAMESPACE

class Hotel : public QMainWindow
{
    Q_OBJECT

public:
    Hotel(QWidget *parent = nullptr);
    ~Hotel();

private:
    void SetConnections();


    QMap<QString, QString> answers_;
    Ui::Hotel *ui;

};
