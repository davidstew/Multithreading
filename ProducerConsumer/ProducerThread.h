#ifndef PRODUCERTHREAD_H
#define PRODUCERTHREAD_H
#include <thread>
#include <mutex>
#include "common.h"
using namespace std;

class ProducerThread {
    public:
        ProducerThread(Simple&);
        void run();
        void join();
    private:
        thread producerThread;
        Simple s;
};
#endif
