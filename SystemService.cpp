#include "SystemService.h"

MessageList* SystemService::messageList = NULL;

SystemService::SystemService()
{
    //TODO read params from config
    socket = std::make_unique<Socket>("127.0.0.1",23);
    socket->open();
    connect(&(*socket), SIGNAL(onData(QByteArray)),this, SLOT(onSocketData(QByteArray)));
}

void SystemService::onSocketData(QByteArray data){
    QString str(data);
    if(SystemService::messageList != NULL){
        SystemService::messageList->addElement(str);
    }

}
