#include "Thermostat.h"

void Thermostat::raiseTemp()
{
    this->desiredTemp += 1.;
}

void Thermostat::lowerTemp()
{
    this->desiredTemp -= 1.;
}

void Thermostat::update(double temp)
{
    curTemp = temp;
    switch(state)
    {
        case (THERMOSTAT_OFF):
            if (desiredTemp - threshold >= curTemp)
            {
                //temperature is too cold
                state = THERMOSTAT_HEATING;
            }
            
            if( desiredTemp - highHeatThreshold >= curTemp)
            {
                state = THERMOSTAT_HIGH_HEAT;
            }
            else 
            {
                //temp fine/too hot
            }
            break;
        case (THERMOSTAT_HEATING):
        case (THERMOSTAT_HIGH_HEAT):
        
        if (curTemp + threshold >= desiredTemp )
        {
            //temperature is too cold
            state = THERMOSTAT_OFF;
            break;
        }
        
            
        if(desiredTemp - highHeatThreshold >= curTemp)
        {
            state = THERMOSTAT_HIGH_HEAT;
        } 
        else
        {
            state = THERMOSTAT_HEATING;
        }
        break;
        default:
            state = THERMOSTAT_OFF;
            break;
    }
}

double Thermostat::getDesiredTemp()
{
    return this->desiredTemp;
}

int Thermostat::getState()
{
    return this->state;
}
