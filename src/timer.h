#ifndef CG_ASSIGNMENT_TIMER_H
#define CG_ASSIGNMENT_TIMER_H


class Timer {
public:
    Timer() {
        prev = 0;
    }

    Timer(double interval);

    double interval;

    bool processTick();

private:
    double prev;
};

#endif // TIMER_H
