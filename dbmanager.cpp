#include "dbmanager.h"
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
bool DBManager::connectToDatabase(const QString& path) {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(path);
    if (!db.open()) {
        qDebug() << "Error connecting to DB:" << db.lastError().text();
        return false;
    }

    qDebug() << "DB connected success";
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
    if (!query.exec(bookingsSql)) {
        qDebug() << "Ошибка создания таблицы bookings:" << query.lastError().text();
    } else {
        qDebug() << "Table bookings created.";
    }
}


RoomCheckResult DBManager::hasFreeRoom(const QString& startDate, const QString& endDate) {
    //is available any room
    QSqlQuery roomQuery("SELECT COUNT(*) FROM rooms");
    if (!roomQuery.exec() || !roomQuery.next()) {
        qDebug() << "[ERROR] Ошибка при проверке количества комнат:" << roomQuery.lastError().text();
        return RoomCheckResult::NoRooms;
    }

    int totalRooms = roomQuery.value(0).toInt();
    if (totalRooms == 0) {
        qDebug() << "[INFO] В базе данных нет зарегистрированных комнат.";
        return RoomCheckResult::NoRooms;
    }

//requesting free rooms
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
        qDebug() << "[ERROR] SQL request Error" << query.lastError().text();
        return RoomCheckResult::NoFreeRooms;
    }

    if (query.next()) {
        qDebug() << "[SUCCESS] Found free room.";
        return RoomCheckResult::FreeRoomExists;
    } else {
        qDebug() << "[INFO] All rooms are busy for this time.";
        return RoomCheckResult::NoFreeRooms;
    }
}



void DBManager::addRoom(const QString& startDate, const QString& endDate,
                        const QString& name, const QString& surname,
                        const QString& email, const QString& passport,
                        const int paymentStatus)
{
    QSqlQuery query;

    int nextRoomId = 300;
    if (!query.exec("SELECT MAX(id) FROM rooms")) {
        qDebug() << "Error getting max room_id:" << query.lastError().text();
    } else if (query.next()) {
        int lastId = query.value(0).toInt();
        if (lastId == 0) {
            nextRoomId = 300;
        } else if (lastId % 100 == 12) {
            nextRoomId = ((lastId / 100 + 1) * 100);
        } else {
            nextRoomId = lastId + 1;
        }
    }

    query.prepare("INSERT INTO rooms (id, bookings) VALUES (:id, '')");
    query.bindValue(":id", nextRoomId);
    if (!query.exec()) {
        qDebug() << "Error adding room:" << query.lastError().text();
        return;
    }


    query.prepare("INSERT INTO bookings (room_id, start_date, end_date, name, surname, email, passport, payment_status) "
                  "VALUES (:room_id, :start_date, :end_date, :name, :surname, :email, :passport, :payment_status)");
    query.bindValue(":room_id", nextRoomId);
    query.bindValue(":start_date", startDate);
    query.bindValue(":end_date", endDate);
    query.bindValue(":name", name);
    query.bindValue(":surname", surname);
    query.bindValue(":email", email);
    query.bindValue(":passport", passport);
    query.bindValue(":payment_status", paymentStatus);

    if (!query.exec()) {
        qDebug() << "Error adding booking:" << query.lastError().text();
    } else {
        qDebug() << "Room" << nextRoomId << "and booking added successfully.";
    }
}

