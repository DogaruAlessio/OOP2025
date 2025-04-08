#include "Circuit.h"
using namespace std;


Circuit::Circuit()
{
    masina = new Car * [nrMax];
}

void Circuit::SetLength(int len)
{
    this->length = len;
}

void Circuit::SetWeather(Weather type)
{
    this->weather = type;
}

void Circuit::Race()
{
    int i;
    int* vec = new int[nrMasiniParticipante + 1];
    for (i = 0; i < nrMasiniParticipante; i++)
        vec[i] = masina[i]->Run(weather, length);
    this->winners = vec;
}

void Circuit::AddCar(Car* competitor)
{
    int i;
    if (nrMasiniParticipante > nrMax)
    {
        Car** temp = new Car * [nrMax + nrMax / 2];
        int* tempwinners = new int[nrMax + nrMax / 2];
        for (i = 0; i < nrMasiniParticipante; i++)
        {
            temp[i] = masina[i];
            tempwinners[i] = winners[i];
        }

        delete[] masina;
        delete[] winners;

        masina = temp;
        winners = tempwinners;

        nrMax += nrMax / 2;
    }
    masina[nrMasiniParticipante++] = competitor;
}

void Circuit::ShowFinalRanks()
{
    int i, j;
    for (i = 0; i < nrMasiniParticipante - 1; i++)
        for (j = i + 1; j < nrMasiniParticipante; j++)
            if (winners[i] > winners[j])
            {
                swap(winners[i], winners[j]);
                swap(masina[i], masina[j]);
            }

    cout << "\-----------Au Terminat Cursa--------\n";
    for (i = 0; i < nrMasiniParticipante; i++)
        if (winners[i] >= 0)
            cout << masina[i]->getName() << '\n';
}

void Circuit::ShowWhoDidNotFinish()
{
    int i;
    cout << "\n----------N-au Terminat Cursa--------\n";
    for (i = 0; i < nrMasiniParticipante; i++)
        if (winners[i] == -1)
            cout << masina[i]->getName() << '\n';
}
