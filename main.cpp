#include "Messages.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Messages w;
    w.show();
    return a.exec();
}
