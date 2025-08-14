#include "dbmanager.h"
#include <QSqlError>
#include <QSqlQuery>
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

void DBManager::createTables() {
    QSqlQuery query;
    QString sql = "CREATE TABLE IF NOT EXISTS rooms ("
                  "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                  "bookings TEXT NOT NULL);";

    if (!query.exec(sql)) {
        qDebug() << "Table create Error" << query.lastError().text();
    } else {
        qDebug() << "Table rooms created.";
    }

    QString bookingsSql = "CREATE TABLE IF NOT EXISTS bookings ("
                          "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                          "room_id INTEGER NOT NULL, "
                          "start_date TEXT NOT NULL, "
                          "end_date TEXT NOT NULL, "
                          "name TEXT NOT NULL,"
                          "surname TEXT NOT NULL,"
                          "passport TEXT NOT NULL,"
                          "email TEXT NOT NULL,"
                          "payment_status INTEGER NOT NULL,"
                          "FOREIGN KEY(room_id) REFERENCES rooms(id));";
    qDebug() << "Shit";
    if (!query.exec(bookingsSql)) {
        qDebug() << "Ошибка создания таблицы bookings:" << query.lastError().text();
    } else {
        qDebug() << "Таблица bookings создана.";
    }
}


RoomCheckResult DBManager::hasFreeRoom(const QString& startDate, const QString& endDate) {
    // Сначала проверим, есть ли вообще комнаты
    QSqlQuery roomQuery("SELECT COUNT(*) FROM rooms");
    if (!roomQuery.exec() || !roomQuery.next()) {
        qDebug() << "[ERROR] Ошибка при проверке количества комнат:" << roomQuery.lastError().text();
        return RoomCheckResult::NoRooms; // или выбросить исключение
    }

    int totalRooms = roomQuery.value(0).toInt();
    if (totalRooms == 0) {
        qDebug() << "[INFO] В базе данных нет зарегистрированных комнат.";
        return RoomCheckResult::NoRooms;
    }

    // Проверим наличие свободных комнат
    QSqlQuery query;

    query.prepare(R"(
    SELECT id
    FROM rooms
    WHERE id NOT IN (
        SELECT room_id
        FROM bookings
        WHERE NOT (end_date <= :start OR start_date >= :end)
    )
    AND id NOT IN (
        SELECT room_id
        FROM bookings
        WHERE start_date = :start
          AND end_date = :end
    )
    LIMIT 1;

   )");

    query.bindValue(":start", startDate);
    query.bindValue(":end", endDate);

    if (!query.exec()) {
        qDebug() << "[ERROR] Ошибка выполнения SQL-запроса:" << query.lastError().text();
        return RoomCheckResult::NoFreeRooms;
    }

    if (query.next()) {
        qDebug() << "[SUCCESS] Найдена свободная комната.";
        return RoomCheckResult::FreeRoomExists;
    } else {
        qDebug() << "[INFO] Комнаты есть, но все заняты на указанный период.";
        return RoomCheckResult::NoFreeRooms;
    }
}



void DBManager::addRoom(const int number,const QString& startDate, const QString& endDate, const QString& name, const QString& surname,const QString& email, const QString& passport, const int PaymentStatus) {
    QSqlQuery query;
    qDebug() << "ENER SHIT";
    query.prepare("INSERT INTO bookings (room_id, start_date, end_date, name, surname, email, passport, payment_status) "
                  "VALUES (:room_id, :start_date, :end_date, :name, :surname, :email, :passport, :payment_status)");
    query.bindValue(":room_id", number);
    query.bindValue(":start_date", startDate);
    query.bindValue(":end_date", endDate);
    query.bindValue(":name", name);
    query.bindValue(":surname", surname);
    query.bindValue(":email", email);
    query.bindValue(":passport", passport);
    query.bindValue(":payment_status", PaymentStatus);



    qDebug() <<  number;
    qDebug() <<  startDate;
    qDebug() <<  endDate;
    qDebug() <<  name;
    qDebug() <<  surname;
    qDebug() <<  email;
    qDebug() <<  passport;
    qDebug() <<  PaymentStatus;

    if (!query.exec()) {
        qDebug() << "Ошибка добавления комнаты:" << query.lastError().text();
    } else {
}
}

