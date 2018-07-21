#include <iostream>
#include <mutex>
#include <condition_variable>
#include <cstdlib>
#include <ctime>
#include "ProducerThread.h"
#include "ConsumerThread.h"
#include "Common.h"
using namespace std;

int main() {
    srand( time( NULL ) );
    mutex m;
    Simple simple(m);

    ProducerThread producer(simple);
    ConsumerThread consumer(simple);

    producer.join();
    consumer.join();

    cout << "Main thread" << endl;
    return 0;
}
