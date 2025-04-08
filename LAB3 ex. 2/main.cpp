#include <iostream>
#include <chrono>
#include <thread>
#include "Canvas.h"

int main()
{
    Canvas Canvas;
    Canvas.Clear();

    Canvas.DrawCircle(15, 15, 15, '*');
    Canvas.FillCircle(15, 15, 15, '-');
    Canvas.Print();
    Canvas.Clear();

    Canvas.DrawRectangular(15, 15, 35, 35, '*');
    Canvas.FillRectangular(15, 16, 35, 35, '-');
    Canvas.Print();
    Canvas.Clear();

    Canvas.SetPoint(15, 35, '*');
    Canvas.SetPoint(40, 50, '*');
    Canvas.DrawLine(15, 35, 40, 50, '-');
}
