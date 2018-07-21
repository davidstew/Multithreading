#include "ProducerThread.h"
#include <iostream>
#include <thread>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

ProducerThread::ProducerThread(Simple& simp) : s(simp) {
    producerThread = thread(run, this);
}

void ProducerThread::join() {
    producerThread.join();
}

void ProducerThread::run() {
    int i = 1;
    while (true) {
        s.write(i);
        int sleepTime =  rand() % 10 + 1;
        std::this_thread::sleep_for (std::chrono::milliseconds(sleepTime * 10));
        ++i;
    }
}
