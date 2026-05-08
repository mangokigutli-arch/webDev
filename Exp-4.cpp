#include <iostream>
#include <thread>
using namespace std;

bool flag[2] = {false, false};
int turn;

// Process 0
void process0() {
    flag[0] = true;
    turn = 1;

    while (flag[1] && turn == 1); // wait

    cout << "Process 0 entered in critical section\n";

    flag[0] = false;
}

// Process 1
void process1() {
    flag[1] = true;
    turn = 0;

    while (flag[0] && turn == 0); // wait

    cout << "Process 1 entered in critical section\n";

    flag[1] = false;
}

int main() {
    thread t1(process0);
    thread t2(process1);

    t1.join();
    t2.join();

    return 0;
}
