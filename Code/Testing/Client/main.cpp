#include <QCoreApplication>
#include <QDebug>
#include "client.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug()<<"Hello World! - Client";

    Client *client = new Client();

    return a.exec();
}
