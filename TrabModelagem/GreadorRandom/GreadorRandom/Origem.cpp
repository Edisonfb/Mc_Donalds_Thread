#include <iostream>
#include "Random.h"
using namespace std;
void main()
{
	Random R;
	int i = 0;
	
	for (i; i < 100; i++)
		cout << R.random() << endl;
	i = 0;
	system("pause");
	system("cls");

	for (i; i < 100; i++)
		cout << R.uniforme(8, 20) << endl;
	i = 0;
	system("pause");
	system("cls");

	for (i; i < 100; i++)
		cout << R.exponencial(5) << endl;
	i = 0;
	system("pause");
	system("cls");

	for (i; i < 100; i++)
		cout << R.normal(7, 2) << endl;
	system("pause");
	system("cls");
}