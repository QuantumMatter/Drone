#include "server.h"

Server::Server(QObject *parent) : QObject(parent)
{
    server = new QTcpServer(this);
    server->listen(QHostAddress::Any, 12345);
    connect(server, SIGNAL(newConnection()), this, SLOT(newConnection()));
    //connect(this, SLOT(newConnection()), server, SIGNAL(newConnection()));

    QTextStream s(stdin);
    QString newMessage;
    /*while((newMessage != "quit") || (newMessage != "exit"))
    {
        newMessage = s.readLine();
        for(QTcpSocket *client : clients)
        {
            client->write(newMessage.toLatin1());
        }
    }*/
}

void Server::newConnection()
{
    QTcpSocket *client = server->nextPendingConnection();
    clients<<client;
    connect(client, SIGNAL(readyRead()), this, SLOT(clientSentData()));
    //connect(this, SLOT(clientSentData()), client, SIGNAL(readyRead()));
    client->write(QByteArray("Connected!"));
    qDebug()<<"New Connection";
}

void Server::clientSentData()
{
    qDebug()<<"Client Sent Data";
    QTcpSocket *client;
    QObject *send = sender();
    for(int i = 0; i < clients.length(); i++)
    {
        QTcpSocket *test = clients.at(i);
        if(test == send)
        {
            client = test;
            qDebug()<<"Found Client!";
        }
    }

    QByteArray messageByte = client->readAll();
    QString message = QString(messageByte);
    qDebug()<<message;
}
