#include <QCoreApplication>
#include <QDebug>
#include "server.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug()<<"Hello World! - Master";

    Server *server = new Server();

    return a.exec();
}
