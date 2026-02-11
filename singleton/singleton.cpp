#include<iostream>
#include "singleton.hpp"
using namespace std;


Logger* Logger::loggerInstance = nullptr;
int Logger::ctr = 0;
mutex Logger::mtx;
Logger::Logger()
{
    ctr++;
    cout<<"New instance created.No of instances "<< ctr << endl;
}

void Logger::log(string message)
{
    cout<<"Log: "<<message<<endl;
}


Logger* Logger::getLogger()
{
    if(loggerInstance == nullptr){
    mtx.lock();
    if(loggerInstance == nullptr)
    {
        loggerInstance = new Logger();
    }

    mtx.unlock();
}

    return loggerInstance;
}