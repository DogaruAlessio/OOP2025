#include <iostream>
#include <cstring>
#include <cmath>
#include "Canvas.h"

using namespace std;

Canvas::Canvas(int width, int height)
{
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			matrix[i][j] = ' ';
		}
	}
}

void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
	int centerX = x + ray;
	int centerY = y + ray;
	int dist;

	for (int i = x; i <= x + 2 * ray; i++)
	{
		for (int j = y; j <= y + 2 * ray; j++)
		{
			dist = (i - ray) * (i - ray) + (j - ray) * (j - ray);
			if (dist <= ray * ray)
			{
				matrix[i][j] = ch;
			}
		}
	}

	for (int i = x; i <= x + 2 * ray; i++)
	{
		for (int j = y; j <= y + 2 * ray; j++)
		{
			if (dist <= (ray - 1) * (ray - 1))
			{
				matrix[i][j] = ' ';
			}
		}
	}
}

void Canvas::FillCircle(int x, int y, int ray, char ch)
{
	int centerX = x + ray;
	int centerY = y + ray;
	int dist;

	for (int i = x; i <= x + 2 * ray; i++)
	{
		for (int j = y; j <= y + 2 * ray; j++)
		{
			dist = (i - centerX) * (i - centerX) + (j - centerY) * (j - centerY);
			if (dist <= (ray - 1) * (ray - 1))
			{
				matrix[i][j] = ch;
			}
		}
	}
}

void Canvas::DrawRectangular(int left, int top, int right, int bottom, char ch)
{
	for (int i = top; i <= bottom; i++)
	{
		matrix[i][left] = ch;
		matrix[i][right] = ch;
	}

	for (int i = right; i <= left; i++)
	{
		matrix[top][i] = ch;
		matrix[bottom][i] = ch;
	}
}

void Canvas::FillRectangular(int left, int top, int right, int bottom, char ch)
{
	for (int i = top; i <= bottom; i++)
	{
		for (int j = left; j <= right; j++)
		{
			matrix[i][j] = ch;
		}
	}
}

void Canvas::SetPoint(int x, int y, char ch)
{
	matrix[y][x] = ch;
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
	int dx = abs(x2 - x1);
	int dy = -abs(y2 - y1);
	int sx, sy;
	//deplasare pe dreapta
	if (x1 < x2)
		sx = 1;
	else
		sx = -1;

	//deplasare in sus
	if (y1 < y2)
		sy = 1;
	else
		sy = -1;

	int error = dx + dy;
	int e2;

	while (true)
	{
		matrix[y1][x1] = ch;
		if (x1 == x2 && y1 == y2)
		{
			break;
		}

		e2 = 2 * error;
		//deplasare pe axa X
		if (e2 >= dy)
		{
			if (x1 == x2)
			{
				break;
			}
			error = error + dy;
			x1 = x1 + sx;
		}

		//deplasare pe axa Y
		if (e2 <= dx)
		{
			if (y1 == y2)
			{
				break;
			}
			error = error + dx;
			y1 = y1 + sy;
		}
	}
}


void Canvas::Print()
{
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			cout << matrix[i][j] << ' ';
		}
		cout << endl;
	}
}

void Canvas::Clear()
{
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			matrix[i][j] = ' ';
		}
	}
}


