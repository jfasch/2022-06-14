#include "sensors.h"
#include <iostream>
#include <memory>

using namespace std;

unique_ptr<Sensor> create_random_sensor(double low, double high)
{
    unique_ptr<Sensor> rndsensor(new RandomSensor(low, high));
    return rndsensor;
}


int main()
{
    auto sensor = create_random_sensor(10.5, 36.5);
    cout << sensor->get_temperature() << endl;

    auto another_sensor = std::move(sensor);

    cout << another_sensor->get_temperature() << endl; // ok
    cout << sensor->get_temperature() << endl; // segfault

    return 0;
}
