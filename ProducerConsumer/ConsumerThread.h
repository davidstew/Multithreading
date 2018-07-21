#ifndef CONSUMERTHREAD_H
#define CONSUMERTHREAD_H
#include <thread>
#include <mutex>
#include "common.h"
using namespace std;

class ConsumerThread {
    public:
        ConsumerThread(Simple&);
        void run();
        void join();
    private:
        thread consumerThread;
        Simple& s;

};
#endif

