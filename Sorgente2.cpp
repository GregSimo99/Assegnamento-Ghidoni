//Perini Mattia

#include <iostream>
#include <stdlib.h>
#include "header.h"

using namespace std;

int Azienda::prox_mese() {
	++mese; //mese successivo
	_sleep(1500); //attesa di 1.5 secondi per simulare il trascorrere dei mesi
	cout << "--------  " << mese << "° mese  --------" << endl;

	/*for (int i = 0; i < cAttesa.size(); ++i) { //decremento di un mese il tempo di attesa dei componenti
		Componente c = cAttesa[i];
		if (c.get_arrivo() != 0) --c.get_arrivo;
		else
			controllo_arrivi(); //quando arriva a 0 il componente è arrivato
	}*/
	return mese;
}

void produzione() {

}

bool ricerca_comp(int id) { //Controlla i componenti in magazzino per l'ordine
	 
}