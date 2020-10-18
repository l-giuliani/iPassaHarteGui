#ifndef SYSTEMSERVICE_H
#define SYSTEMSERVICE_H

#include <memory>

#include "messagelist.h"
#include "driver/socket/Socket.h"

class SystemService : public QObject
{
    Q_OBJECT
    std::unique_ptr<Socket> socket;


public:
    static MessageList* messageList;
    SystemService();
    static void setMessageList(MessageList* ml){
        SystemService::messageList = ml;
    }

public slots:
    void onSocketData(QByteArray data);
};

#endif // SYSTEMSERVICE_H
