#include "ConsumerThread.h"
#include <iostream>
#include <thread>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

ConsumerThread::ConsumerThread(Simple& simp) : s(simp) {
    consumerThread = thread(run, this);
}

void ConsumerThread::join() {
    consumerThread.join();
}

void ConsumerThread::run() {
    while(true) {
        s.read();
        int sleepTime =  rand() % 10 + 1;
        std::this_thread::sleep_for (std::chrono::milliseconds(sleepTime));
    }
}

