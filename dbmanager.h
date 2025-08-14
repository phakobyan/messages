#pragma once
#include <QSqlDatabase>
#include <QString>

enum class RoomCheckResult {
    NoRooms,
    NoFreeRooms,
    FreeRoomExists
};

class DBManager {
public:
    static bool connectToDatabase(const QString& path);
    static void createTables();
    static RoomCheckResult hasFreeRoom(const QString& startDate, const QString& endDate);
    static void insertTestRooms();
    void addRoom(const int number,const QString& startDate, const QString& endDate, const QString& name, const QString& surename,const QString& email, const QString& passport, const int PaymentStatus);
};

