#include "TrafficLight.h"

std::string TrafficLight::getColour()
{
    switch (this->_state)
    {
        case STATE_INIT:
            return COLOR_DEFAULT;
        case STATE_STOP:
            return COLOR_RED;
        case STATE_GO:
            return COLOR_GREEN;
        case STATE_SLOW:
            return COLOR_YELLOW;
        default:
            return COLOR_DEFAULT;
    }
}

int TrafficLight::sleepAfterTime()
{
    switch (this->_state)
    {
        case STATE_INIT:
            return SLEEP_AFTER_INIT;
        case STATE_STOP:
            return SLEEP_AFTER_STOP;
        case STATE_GO:
            return SLEEP_AFTER_GO;
        case STATE_SLOW:
            return SLEEP_AFTER_SLOW;
        default:
            return SLEEP_AFTER_INIT;
    }
}

void TrafficLight::transition()
{
    switch (this->_state)
    {
        case STATE_INIT:
            this->_state = STATE_STOP;
            break;
        case STATE_STOP:
            this->_state = STATE_GO;
            break;
        case STATE_GO:
            this->_state = STATE_SLOW;
            break;
        case STATE_SLOW:
            this->_state = STATE_STOP;
            break;
        default:
            this->_state = STATE_STOP;
            break;
    }
}
