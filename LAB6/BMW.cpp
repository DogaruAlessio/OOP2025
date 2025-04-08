#include "BMW.h"

BMW::BMW()
{
    this->name = new char[10];
    strcpy_s(this->name, 10, "BMW");
    this->fuel_capacity = 350;
    this->fuel_consumption = 7;
    this->avg_speed = 80;
}
char* BMW::getName()
{
    return this->name;
}
int BMW::getFuelCapacity()
{
    return this->fuel_capacity;
}
int BMW::getFuelConsumption()
{
    return this->fuel_consumption;
}
int BMW::getAverageSpeed()
{
    return this->avg_speed;
}

void BMW::setSpeed(Weather type)
{
    if (type == Weather::Rain)
        this->avg_speed = this->avg_speed - std::max(4, rand() % 10);
    else if (type == Weather::Snow)
        this->avg_speed = this->avg_speed - std::max(7, rand() % 20);
}

int BMW::Run(Weather type, int len)
{
    this->setSpeed(type);
    int gasNeeded = (this->getFuelConsumption() * len) / 100;
    if (gasNeeded > this->getFuelCapacity())
        return -1;
    int time = (len / (this->getAverageSpeed() * 1.0)) * 60;
    return time;
}