#ifndef SOCKET_H
#define SOCKET_H

#include <QTcpSocket>
#include <QObject>
class Socket : public QObject
{
    Q_OBJECT
    QTcpSocket socket;
    QString ip;
    quint16 port;
    bool isConnected;

public:
    Socket(QString ip, quint16 port){
        this->ip = ip;
        this->port = port;
        this->isConnected = false;

        connect(&socket, SIGNAL(connected()),this, SLOT(connected()));
        connect(&socket, SIGNAL(disconnected()),this, SLOT(disconnected()));
        connect(&socket, SIGNAL(readyRead()),this, SLOT(readyRead()));
    }

    void open();

public slots:
    void connected();
    void disconnected();
    void readyRead();

signals:
    void onData(QByteArray data);
};

#endif // SOCKET_H
