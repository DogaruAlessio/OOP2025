#include "Seat.h"

Seat::Seat()
{
    this->name = new char[5];
    strcpy_s(this->name, 5, "Seat");
    this->fuel_capacity = 300;
    this->fuel_consumption = 30;
    this->avg_speed = 155;
}

char* Seat::getName()
{
    return this->name;
}

int Seat::getFuelCapacity()
{
    return this->fuel_capacity;
}

int Seat::getFuelConsumption()
{
    return this->fuel_consumption;
}

int Seat::getAverageSpeed()
{
    return this->avg_speed;
}

void Seat::setSpeed(Weather type)
{
    if (type == Weather::Rain)
        this->avg_speed = this->avg_speed - std::max(1, rand() % 5);
    else if (type == Weather::Snow)
        this->avg_speed = this->avg_speed - std::max(3, rand() % 10);
}

int Seat::Run(Weather type, int len)
{
    this->setSpeed(type);
    int gasNeeded = (this->getFuelConsumption() * len) / 100;
    if (gasNeeded > this->getFuelCapacity())
        return -1;
    int time = (len / (this->getAverageSpeed() * 1.0)) * 60;
    return time;
}