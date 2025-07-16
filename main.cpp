#include "messages.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    messages w;
    w.show();
    return a.exec();
}
