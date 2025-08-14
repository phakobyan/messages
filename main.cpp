#include "firstwindow.h"
#include <QScreen>
#include <QApplication>
#include <QApplication>
#include "dbmanager.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FirstWindow w;
    w.show();
    w.move(QApplication::primaryScreen()->availableGeometry().center() - w.rect().center());
    if (!DBManager::connectToDatabase("my_qt_db.sqlite")) {
        return -1;
    }
    //DBManager::createTables();
    //DBManager::insertTestRooms();
    return a.exec();

}
