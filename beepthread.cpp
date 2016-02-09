#include "beepthread.h"

#ifdef Q_OS_WIN
#include <Windows.h>
#else
#include <QApplication>
#endif

BeepThread::BeepThread(QObject *parent) :
    QThread(parent),
    prng(std::random_device()()),
    delayMin(0),
    delayMax(0)
{
}

void BeepThread::run()
{
    prngDist = std::uniform_int_distribution<intType>(delayMin, delayMax);

    while (true) {
#ifdef Q_OS_WIN
        Beep(600, 300);
#else
        QApplication::beep();
#endif

        msleep(prngDist(prng));
    }
}

void BeepThread::setDelayMin(intType minimumDelay)
{
    delayMin = minimumDelay;
}

void BeepThread::setDelayMax(intType maximumDelay)
{
    delayMax = maximumDelay;
}
