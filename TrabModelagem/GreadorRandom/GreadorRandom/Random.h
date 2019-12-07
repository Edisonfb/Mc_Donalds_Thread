#pragma once
#include <time.h>
#include <iostream>

using namespace std;
class Random
{
private:
	unsigned int seed, a, c, m, X;
	double resultado;
public:
	double random();
	double uniforme(int, int);
	double exponencial(int);
	double normal(int, int);

	Random();
	~Random();
};

