#include "MessageList.h"
#include "SystemService.h"

MessageList::MessageList() {
    //startTimer(1000);
    SystemService::setMessageList(this);
}

void MessageList::addElement(QString str){
    mutex.lock();
    dataList.push_front(str);
    if(dataList.size() > 15){
        dataList.pop_back();
    }
    emit modelChanged();
    mutex.unlock();
}

QStringList MessageList::model() {
    return dataList;
}
