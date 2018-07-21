#ifndef COMMON_H
#define COMMON_H
#include <iostream>
#include <queue>
#include <mutex>
#include <condition_variable>
using namespace std;

class Simple {
public:
    mutex& m;
    inline Simple(mutex& mu) : m(mu) {}
    void write(int value);
    int read();
private:
    const int CAPACITY = 1;
};
#endif // COMMON_H
