// WaveEquation1D.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <vector>

#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;

int solve(double, int, double, double);

double I(double);



int main()
{
	cout << "Hello" << endl;
	int size;

	int j;
	j = solve(1.0, 10, 0.5, 0.05);
	_getch();
	return 0;
}


int solve(double L, int Nx, double t, double dt)
{
	int Nt = int(round(t / dt));
	double r;
	double dx = L / Nx;
	r = 1.0;
	double **u;

	u = new double *[Nx + 1];

	for (int i = 0; i < (Nx + 1); i++)
	{
		u[i] = new double[Nt + 1];
	}

	for (int i = 0; i < (Nx + 1); i++)
	{
		for (int j = 0; j < (Nt + 1); j++)
		{
			u[i][j] = 0.0;
		}
	}

	for (int i = 0; i < (Nx + 1); i++)
	{
		for (int j = 0; j < (Nt + 1); j++)
		{
			cout << u[i][j] << " ";
		}
		cout << endl;
	}


	//Mesh of points or x's

	double *mshX;

	mshX = new double[Nx + 1];

	for (int i = 0; i < (Nx + 1); i++)
	{
		mshX[i] = 0.0;
	}

	int count = 0;
	for (int i = 0; i < (Nx + 1); i++)
	{
		mshX[i] += count*dx;
		count++;
	}

	//Initialize with Steps time 0 and 1

	for (int i = 1; i < (Nx + 1); i++)
	{
		u[i][0] = I(mshX[i]);
		u[i][1] = (1 - r*r)*I(mshX[i]) + (0.0) + ((r*r) / 2)*(I(mshX[i + 1]) + I(mshX[i - 1]));
	}


	for (int i = 0; i < (Nx + 1); i++)
	{
		for (int j = 0; j < (Nt + 1); j++)
		{
			cout << u[i][j] << " ";
		}
		cout << endl;
	}


	for (int j = 2; j < (Nt + 1); j++)
	{
		for (int i = 1; i < (Nx); i++)
		{
			u[i][j] = (1 - r*r)*u[i][j - 1] + r*r*(u[i - 1][j - 1] + u[i + 1][j - 1]) - u[i][j - 2];
		}
	}



	for (int i = 0; i < (Nx + 1); i++)
	{
		for (int j = 0; j < (Nt + 1); j++)
		{
			cout << u[i][j] << " ";
		}
		cout << endl;
	}



	return 0;
}



double I(double x)
{
	return sin(M_PI * x) + cos(M_PI*x);
}