#include "Fiat.h"

Fiat::Fiat()
{
    this->name = new char[5];
    strcpy_s(this->name, 5, "Fiat");
    this->fuel_capacity = 500;
    this->fuel_consumption = 10;
    this->avg_speed = 170;
}

char* Fiat::getName()
{
    return this->name;
}

int Fiat::getFuelCapacity()
{
    return this->fuel_capacity;
}

int Fiat::getFuelConsumption()
{
    return this->fuel_consumption;
}

int Fiat::getAverageSpeed()
{
    return this->avg_speed;
}

void Fiat::setSpeed(Weather type)
{
    if (type == Weather::Rain)
        this->avg_speed = this->avg_speed - std::max(5, rand() % 15);
    else if (type == Weather::Snow)
        this->avg_speed = this->avg_speed - std::max(10, rand() % 25);
}

int Fiat::Run(Weather type, int len)
{
    this->setSpeed(type);
    int gasNeeded = (this->getFuelConsumption() * len) / 100;
    if (gasNeeded > this->getFuelCapacity())
        return -1;
    int time = (len / (this->getAverageSpeed() * 1.0)) * 60;
    return time;
}
