#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QDebug>
#include <QTcpSocket>
#include <QHostAddress>

class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QObject *parent = 0);

signals:

public slots:
    void connected();
    void serverSentData();

private:
    QTcpSocket *connection;
    QTextStream *s;
};

#endif // CLIENT_H
