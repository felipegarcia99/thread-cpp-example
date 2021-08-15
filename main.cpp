#include <iostream>
#include <thread>

#define LIMIT 1000000

using namespace std;

void task1(){
    for (int i = 0; i < LIMIT; i++){
        cout << "task1 says: " << i << endl;
    }
}

void task2(){
    for (int i = 0; i < LIMIT; i++){
        cout << "task2 says: " << i << endl;
    }
}

int main()
{
    // Constructs the new thread and runs it. Does not block execution.
    thread t1(task1);
    thread t2(task2);

    // Do other things...
    for (int i = 0; i < LIMIT; i++){
        cout << "enquanto isso, no paláio da justiça..." << i << endl;
    }

    // Makes the main thread wait for the new thread to finish execution, therefore blocks its own execution.
    t1.join();
    t2.join();
}