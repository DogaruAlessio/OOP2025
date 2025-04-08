#pragma once
#include "Car.h"

class Volvo : public Car
{
protected:
    char* name;
    int fuel_capacity;
    int fuel_consumption;
    int avg_speed;
public:
    Volvo();
    char* getName();
    int getFuelCapacity();
    int getFuelConsumption();
    int getAverageSpeed();
    int Run(Weather, int);
    void setSpeed(Weather);

};