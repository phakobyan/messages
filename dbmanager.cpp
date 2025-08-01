#include "dbmanager.h"
#include <QSqlError>
#include <QDebug>

bool DBManager::connectToDatabase(const QString& path) {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(path);

    if (!db.open()) {
        qDebug() << "Ошибка подключения к базе данных:" << db.lastError().text();
        return false;
    }

    qDebug() << "База данных подключена успешно!";
    return true;
}
