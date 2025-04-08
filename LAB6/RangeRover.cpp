#include "RangeRover.h"

RangeRover::RangeRover()
{
    this->name = new char[11];
    strcpy_s(this->name, 11, "RangeRover");
    this->fuel_capacity = 20;
    this->fuel_consumption = 40;
    this->avg_speed = 140;
}

char* RangeRover::getName()
{
    return this->name;
}

int RangeRover::getFuelCapacity()
{
    return this->fuel_capacity;
}

int RangeRover::getFuelConsumption()
{
    return this->fuel_consumption;
}

int RangeRover::getAverageSpeed()
{
    return this->avg_speed;
}

void RangeRover::setSpeed(Weather type)
{
    if (type == Weather::Rain)
        this->avg_speed = this->avg_speed - std::max(3, rand() % 5);
    else if (type == Weather::Snow)
        this->avg_speed = this->avg_speed - std::max(10, rand() % 10);
}

int RangeRover::Run(Weather type, int len)
{
    this->setSpeed(type);
    int gasNeeded = (this->getFuelConsumption() * len) / 100;
    if (gasNeeded > this->getFuelCapacity())
        return -1;
    int time = (len / (this->getAverageSpeed() * 1.0)) * 60;
    return time;
}