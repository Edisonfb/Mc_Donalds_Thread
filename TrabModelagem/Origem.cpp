#include <iostream>
#include <thread>
#include <vector>
#include <chrono>
#include <queue>
#include "GreadorRandom\GreadorRandom\Random.h"
#include <string>
#include <string.h>
using namespace std;
using namespace chrono;

time_point<system_clock, system_clock::duration>tempoInicial = system_clock::now();
int cont = 0;
Random R;

class Atendente
{
private:
	time_point<system_clock,system_clock::duration>tempoInicialA = system_clock::now();


	queue<int> FilaClientes;
	
	string nomefila;

	int U_max, U_min, tempo_exe;
	
	thread *T;

public:

	void AtenderCliente()
	{
		do{
			CriarCliente();
		if (!FilaClientes.empty())
			{
				cout << "Cliente sendo atendido no " << nomefila << "\n";
				this_thread::sleep_for(seconds(getTempo()));
				cout << "Cliente saiu em " << duration_cast<chrono::seconds>(system_clock::now() - tempoInicialA).count() << " segundos do " << nomefila << "\n\n";
				FilaClientes.pop();
			}
		} while (duration_cast<seconds>(chrono::system_clock::now() - tempoInicial).count() < tempo_exe);
		cont++;
	};

	void iniciar() {
		
		T = new thread(&Atendente::AtenderCliente, this);
		
	};

	void CriarCliente()
	{
			FilaClientes.push(R.normal(U_max, U_min));
			this->tempoInicialA = system_clock::now();
		
	};

	int getTempo()
	{
		return FilaClientes.front();
	};

	bool FilaVazia() {
		return FilaClientes.empty();
	};

	void SetNome(string x) {
		nomefila = x;
	};

	void Join() {
		if(T)
		if(T->joinable())
			T->join();
	};

	void SetValores(int U_max, int U_min, int tempo_exe)
	{
		this->U_max = U_max;
		this->U_min = U_min;
		this->tempo_exe = tempo_exe;
	};


};

void rodarp(Atendente *x, int U_max, int U_min, int tempo_exe, int qnt_atendente) {
	
	string aux;
	x = new Atendente[qnt_atendente];

	for (int i = 0; i < qnt_atendente; i++) {
		aux = to_string(i);
		x[i].SetNome("caixa_" + aux);
		x[i].SetValores(U_max, U_min, tempo_exe);
		x[i].iniciar();
	}

	

	/*
	V.push_back(x[0]);
	V.push_back(x[1]);
	V.push_back(x[2]);
	V[0].SetNome("caixa_1");
	V[1].SetNome("caixa_2");
	V[2].SetNome("caixa_3");

	V[0].SetValores(U_max, U_min, tempo_exe);
	V[1].SetValores(U_max, U_min, tempo_exe);
	V[2].SetValores(U_max, U_min, tempo_exe);

	V[0].iniciar();
	V[1].iniciar();
	V[2].iniciar();
	V[0].Join();
	V[1].Join();
	V[2].Join();*/


}


int main()
{
	bool rodar = true;
	int escolha;
	//exe(5, 3, 20);
	int min =3, max = 5, tempo = 5;
	Atendente *x;
	x = new Atendente;
	int qnt_atendente = 3;


	rodarp(x, max, min, tempo, qnt_atendente);
	
	do {
		
		
		if (cont == qnt_atendente) {
			
			cout << "O que voce deseja fazer?\n0: interrompe a execucao\n1: executar programa\n2: mudar valores de atendimento\n3: mudar duracao da execucao\n";
			cout << "4: mudar o numero de atendentes\n";
			cin >> escolha;
			switch (escolha) {
			case 0:
			{
				rodar = false;
				break;
			}
			case 1:
			{
				system("cls");
				tempoInicial = system_clock::now();
				rodarp(x, max, min, tempo, qnt_atendente);
				cont = 0;
				break;
			}
			case 2:
			{
				system("cls");
				cout << "digite o valor maximo de tempo de atendimento: ";
				cin >> max;
				cout << "\ndigite o valor minimo de tempo de atendimento: ";
				cin >> min;
				
				break;
			}
			case 3:
			{
				system("cls");
				cout << "digite o valor do tempo de execucao: ";
				cin >> tempo;
				
				break;
			}
			case 4:
			{
				system("cls");
				cout << "digite a quantidade de atendentes: ";
				cin >> qnt_atendente;
				cont = qnt_atendente;
				break;
			}
			default:
			{
				system("cls");
				cout << "digite um valor valido\n";
			
				break;
			}
			
			}
			
		}


		
	} while (rodar);
	for (int i = 0; i < qnt_atendente; i++) {
		x[i].Join();
	}

	system("pause");
	return 0;
}






