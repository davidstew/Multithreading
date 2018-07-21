#include "common.h"
using namespace std;

condition_variable notFull;
condition_variable notEmpty;
std::queue<int> buffer;

void Simple::write(int value) {
        unique_lock<mutex> lck(m, defer_lock);
        lck.lock();
        try {
            while (buffer.size() == CAPACITY) {
                cout << "waiting for NotFull condition" << endl;
                notFull.wait(lck, [&]() { return !(buffer.size() == CAPACITY); } ); //WAIT FOR THE NOTFULL SIGNAL!!
            }

        cout << "Writing " << value << endl;
        buffer.push(value);

        } catch(...) {
            cerr << "exception occurred: ERROR " << endl;
        }
        lck.unlock();
        notEmpty.notify_one();
    }

    int Simple::read() {
        unique_lock<mutex> lck(m, defer_lock);
        lck.lock();
        try {
            while (buffer.size() == 0) {
                cout << "\t\t\t Wait for notEmpty condition" << endl;
                notEmpty.wait(lck, [](){ return !buffer.empty(); } ); //wAIT FOR THE NOTEMPTY SIGNAL!!
            }
        }
        catch(...) {}
        int val = buffer.front();
        cout << "\t\t\t Reading " << val << endl;
        buffer.pop();

        notFull.notify_one();
        lck.unlock();
        return val;
    }
