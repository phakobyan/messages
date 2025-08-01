#pragma once
#include <QSqlDatabase>
#include <QString>

class DBManager {
public:
    static bool connectToDatabase(const QString& path);
};
