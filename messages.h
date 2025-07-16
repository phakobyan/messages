#pragma once
#include <QMainWindow>
#include <QMap>
#include <QString>
QT_BEGIN_NAMESPACE
namespace Ui {
class messages;
}
QT_END_NAMESPACE

class messages : public QMainWindow
{
    Q_OBJECT

public:
    messages(QWidget *parent = nullptr);
    ~messages();

private:
    QMap<QString, QString> answers_;
    void SetConnections();
    Ui::messages *ui;

};
