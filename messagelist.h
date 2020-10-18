#ifndef MESSAGELIST_H
#define MESSAGELIST_H

#include<QStringList>
#include <QObject>
#include <QtQml>
class MessageList : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QStringList model READ model NOTIFY modelChanged)
private:
    QStringList dataList;
    QMutex mutex;

public:
    MessageList();
    void addElement(QString str);
    QStringList model();

    /*void timerEvent(QTimerEvent *e) {
        dataList.push_front("new Element");
        if(dataList.size() > 10){
            dataList.pop_back();
        }
        emit modelChanged();
     }*/

signals:
    void modelChanged();
};

#endif // MESSAGELIST_H
