#include "MessageList.h"

MessageList::MessageList() {
    dataList.append("Item 1");
    dataList.append("Item 2");
    dataList.append("Item 3");

    startTimer(1000);
}

QStringList MessageList::model() {
    return dataList;
}
