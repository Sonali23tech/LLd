#include <iostream>
#include "singleton.hpp"
#include<thread>
using namespace std;

void userLogs1(){
    Logger* logger1 = Logger::getLogger();
    logger1->log("This is the first log message.");   
}

void userLogs2(){
    Logger* logger2 = Logger::getLogger();
    logger2->log("This is the second log message.");
}

int main(){
   thread t1(userLogs1);
   thread t2(userLogs2);

   t1.join();
    t2.join();

    return 0;
}