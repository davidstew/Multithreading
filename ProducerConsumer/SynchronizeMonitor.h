#ifndef SYNCHRONIZE
#define SYNCHRONIZE
#include <iostream>
#include <mutex>
#include <condition_variable>
using namespace std;

class SynchronizeMonitor {
    private:
    mutex m;
    condition_variable cv;

    public:
    unique_lock<mutex> lck;
    SynchronizeMonitor() {

    }
};
#endif // SYNCHRONIZE
