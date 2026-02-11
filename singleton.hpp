#ifndef logger_h
#define logger_h

#include <string>
#include <mutex>
using namespace std;

class Logger
{
    
    Logger();
    Logger(const Logger &);
    Logger& operator=(const Logger &);
    static int ctr;
    static Logger *loggerInstance;
    static mutex mtx;
    public:

        static Logger* getLogger();
        void log(string message);


};

#endif