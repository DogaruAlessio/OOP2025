#include <iostream>
#include <algorithm>
#include "Car.h"


class Circuit
{
private:
    int length;
    Weather weather;
    Car** masina;
    int nrMax = 100;
    int nrMasiniParticipante = 0;
    int* winners;
public:
    Circuit();
    void SetLength(int);
    void SetWeather(Weather);
    void AddCar(Car*);
    void Race();
    void ShowFinalRanks();
    void ShowWhoDidNotFinish();

};
