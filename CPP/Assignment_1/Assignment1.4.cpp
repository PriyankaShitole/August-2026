#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char* argv[])
{
    // Check arguments
    if (argc != 4)
    {
        cout << "Usage : ./sensor_monitor" << endl;
        cout << "Error : Missing arguments." << endl;
        return 1;
    }

    // Convert command-line arguments
    int warn = atoi(argv[1]);
    int critical = atoi(argv[2]);
    int num_readings = atoi(argv[3]);

    // Validate warn and critical
    if (warn >= critical)
    {
        cout << "Error : Warn threshold must be less than Critical threshold." << endl;
        return 1;
    }

    // Validate number of readings
    if (num_readings < 1 || num_readings > 500)
    {
        cout << "Error : Number of readings must be between 1 and 500." << endl;
        return 1;
    }

    // Print configuration
    cout << "Config : Warn=" << warn
         << "°C Critical=" << critical
         << "°C Readings=" << num_readings << endl;

    // Counters
    int normal = 0;
    int warning = 0;
    int criticalCount = 0;
    int shutdown = 0;

    // Generate and classify readings
    for (int i = 0; i < num_readings; i++)
    {
        int temperature = rand() % 70;

        if (temperature < warn)
        {
            normal++;
        }
        else if (temperature < critical)
        {
            warning++;
        }
        else if (temperature < 60)
        {
            criticalCount++;
        }
        else
        {
            shutdown++;
        }
    }

    // Print results
    cout << "Results :" << endl;
    cout << "Normal:" << normal << endl;
    cout << "Warning:" << warning << endl;
    cout << "Critical:" << criticalCount << endl;
    cout << "Shutdown:" << shutdown << endl;

    return 0;
}
