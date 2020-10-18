#include "socket.h"

void Socket::open(){
    socket.connectToHost(this->ip, this->port);
}

void Socket::connected(){
    this->isConnected = true;
}

void Socket::disconnected(){
    this->isConnected = false;
    qDebug() << "Disconnected\n";
}

void Socket::readyRead()
{
    QByteArray qb = socket.readAll();
    emit onData(qb);
}
