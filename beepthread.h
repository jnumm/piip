#ifndef PIIP_BEEPTHREAD_H
#define PIIP_BEEPTHREAD_H

#include <random>
#include <QThread>

/* A thread that beeps in random intervals.
 *
 * The random interval boundaries can be set with methods setDelayMin() and
 * setDelayMax().
 */
class BeepThread : public QThread
{
    Q_OBJECT

public:
    /* This integer type is used for expressing milliseconds. */
    using intType = unsigned long;

    BeepThread(QObject *parent = nullptr);

    void run() Q_DECL_OVERRIDE;

    void setDelayMin(intType minimumDelay);
    void setDelayMax(intType maximumDelay);

private:
    std::mt19937 prng;
    std::uniform_int_distribution<intType> prngDist;

    intType delayMin;
    intType delayMax;
};

#endif // PIIP_BEEPTHREAD_H
