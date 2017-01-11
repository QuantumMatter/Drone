#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QList>

class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = 0);

signals:

public slots:
    void newConnection();
    void clientSentData();

private:
    QTcpServer *server;
    QList<QTcpSocket *> clients;
};

#endif // SERVER_H
