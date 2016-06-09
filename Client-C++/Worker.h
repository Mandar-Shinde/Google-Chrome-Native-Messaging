#ifndef PARA_H
#define PARA_H

#include <qthread.h>
#include <iostream>

class Worker : public QThread {
    Q_OBJECT
public:
    void run();
signals:
    void UpdateMessage(const QString &);
};

#endif
