#pragma once
#include "Car.h"

class Fiat : public Car
{
protected:
    char* name;
    int fuel_capacity;
    int fuel_consumption;
    int avg_speed;
public:
    Fiat();
    char* getName();
    int getFuelCapacity();
    int getFuelConsumption();
    int getAverageSpeed();
    int Run(Weather, int);
    void setSpeed(Weather);

};