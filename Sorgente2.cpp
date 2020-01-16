//Perini Mattia

#include <iostream>
#include <stdlib.h>
#include "header.h"

using namespace std;

void componente::tempo_attesa(int tempo, int mese) {
	int anno = 2020;
	mese = mese + tempo;

	while (mese > 12) //ogni volta che il mese è più di 12, incrementa l'anno e reimposta il mese
	do{
		++anno;
		mese = mese - 12;
	}

	_sleep(2000); //attesa di 2 secondi per il trascorrere dei mesi

	cout << tempo << " mesi dopo\nSiamo in ";
	switch (mese)
	{
	case 1:
		cout << "gennaio ";
		break;
	case 2:
		cout << "febbraio ";
		break;
	case 3:
		cout << "marzo ";
		break;
	case 4:
		cout << "aprile ";
		break;
	case 5:
		cout << "maggio ";
		break;
	case 6:
		cout << "giugno ";
		break;
	case 7:
		cout << "luglio ";
		break;
	case 8:
		cout << "agosto ";
		break;
	case 9:
		cout << "settembre ";
		break;
	case 10:
		cout << "ottobre ";
		break;
	case 11:
		cout << "novembre ";
		break;
	case 12:
		cout << "dicembre ";
		break;
	default: //messaggio di errore?
		break;
	}

	cout << anno << endl;
}
