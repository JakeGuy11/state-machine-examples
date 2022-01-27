#define THERMOSTAT_INIT 0
#define THERMOSTAT_OFF 1
#define THERMOSTAT_HEATING 2
#define THERMOSTAT_HIGH_HEAT 3

#include <thread>

class Thermostat
{
    double curTemp = 20.;
    double desiredTemp = 20.;
    double threshold = 0.25;
    double highHeatThreshold = 5.;
    int state = THERMOSTAT_INIT;
    
    public:
        void raiseTemp();
        void lowerTemp();
        void update(double temp);
        double getDesiredTemp();
        int getState();
};
