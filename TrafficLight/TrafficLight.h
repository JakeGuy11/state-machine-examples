#include <string>

#define STATE_INIT 0
#define STATE_STOP 1
#define STATE_SLOW 2
#define STATE_GO 3

#define SLEEP_AFTER_INIT 0
#define SLEEP_AFTER_STOP 8
#define SLEEP_AFTER_SLOW 3
#define SLEEP_AFTER_GO 10

#define COLOR_RED "\033[31m"
#define COLOR_GREEN "\033[32m"
#define COLOR_YELLOW "\033[33m"
#define COLOR_DEFAULT "\033[39m"

class TrafficLight
{
    public:
        std::string getColour();
        int sleepAfterTime();
        void transition();

    private:
        int _state = STATE_INIT;
    
};