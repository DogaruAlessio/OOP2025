#include "Volvo.h"

Volvo::Volvo()
{
    this->name = new char[6];
    strcpy_s(this->name, 6, "Volvo");
    this->fuel_capacity = 250;
    this->fuel_consumption = 40;
    this->avg_speed = 120;
}

char* Volvo::getName()
{
    return this->name;
}

int Volvo::getFuelCapacity()
{
    return this->fuel_capacity;
}

int Volvo::getFuelConsumption()
{
    return this->fuel_consumption;
}

int Volvo::getAverageSpeed()
{
    return this->avg_speed;
}

void Volvo::setSpeed(Weather type)
{
    if (type == Weather::Rain) //type == 0
        this->avg_speed = this->avg_speed - std::max(1, rand() % 10);
    else if (type == Weather::Snow)
        this->avg_speed = this->avg_speed - std::max(5, rand() % 15);
}

int Volvo::Run(Weather type, int len)
{
    this->setSpeed(type);
    int gasNeeded = (this->getFuelConsumption() * len) / 100;
    if (gasNeeded > this->getFuelCapacity())
        return -1;
    int time = (len / (this->getAverageSpeed() * 1.0)) * 60;
    return time;
}