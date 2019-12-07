#include "Random.h"



double Random::random()
{
	X = (a * seed + c) % m;
	seed = X;
	return (double)X / ((double)m - 1);
}

double Random::uniforme(int MAX, int MIN)
{
	return resultado = MIN + (MAX - MIN) * random();
}

double Random::exponencial(int media)
{
	return resultado = - media * log(1 - random());
}

double Random::normal(int media, int desviopadrao)
{

	double V1, V2, W, Y, X1;
	do {
		V1 = 2 * random() - 1;
		V2 = 2 * random() - 1;
		W = pow(V1, 2) + pow(V2, 2);
	} while (W > 1);
	Y = sqrt(((-2 * log(W)) / W));
	X1 = V1 * Y;
	if (X1 < 0)
		X1 *= -1;
	return media + desviopadrao * X1;
}

Random::Random()
{
	seed = 32767;
	a = 16807;
	c = 0;
	m = 2147483647;
}


Random::~Random()
{
}
