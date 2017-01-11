#include "client.h"

Client::Client(QObject *parent) : QObject(parent)
{
    connection = new QTcpSocket();
    qDebug()<<"Enter IP Address: ";
    s = new QTextStream(stdin);
    QString value = s->readLine();

    connect(connection, SIGNAL(connected()), this, SLOT(connected()));

    connection->connectToHost(QHostAddress(value), 12345);
}

void Client::connected()
{
    qDebug()<<"Connected To Host!";
    connect(connection, SIGNAL(readyRead()), this, SLOT(serverSentData()));
    QString newMessage;
    while((newMessage != "quit") || (newMessage != "exit"))
    {
        newMessage = s->readLine();
        connection->write(newMessage.toLatin1());
        connection->flush();
    }
}

void Client::serverSentData()
{
    QByteArray messageBytes = connection->readAll();
    QString message(messageBytes);
    qDebug()<<"Received Data: "<<message;
}
