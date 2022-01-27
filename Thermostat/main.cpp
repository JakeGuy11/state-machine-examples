#include <iostream>
#include "Thermostat.h"

Thermostat thermostat;

int main()
{

    while (true)
    {
        // Get the temperature as a string
        std::string temp;
        printf("Enter the current temperature: \n");
        std::cin >> temp;
        double temp_double;
        
        // Try getting the temperature as a string
        try
        {
            temp_double = std::stod(temp);
        }
        catch (const std::invalid_argument& ia)
        {
            printf("invalid number \n");
            continue;
        }
        
        // Update the temp
        thermostat.update(temp_double);
        
        // Ask for a command
        std::string command;
        printf("enter a command(+/-/X): \n");
        std::cin >> command;
        
        // Handle the command
        if (command == "+")
        {
            thermostat.raiseTemp();
        }
        else if (command == "-")
        {
            thermostat.lowerTemp();
        }
        else if (command != "X")
        {
            printf("invalid command \n");
        }

        // Update the user
        printf("desired temp: %.1f, cur temp: %.1f \n", thermostat.getDesiredTemp(), temp_double); 
        printf("current state: %d \n\n", thermostat.getState());
    }

    return 0;
}