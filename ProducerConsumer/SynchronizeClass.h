#ifndef SYNCHRONIZE
#define SYNCHRONIZE
#include <iostream>
#include <mutex>
#include <condition_variable>
using namespace std;

class SynchronizeMonitor {
    private:
    mutex m;
    unique_lock<mutex> lock;
    condition_variable cv;
    public:
    SynchronizeMonitor() {
      unique_lock<mutex> lock(m);
    }
};
#endif // SYNCHRONIZE
