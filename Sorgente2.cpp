//Perini Mattia	  1162399

#include <iostream>
#include <stdlib.h>
#include "header.h"

using namespace std;


int Azienda::prox_mese() {
	++mese; //mese successivo
	_sleep(1500); //attesa di 1.5 secondi per simulare il trascorrere dei mesi
	cout << "----------  " << mese << "° mese  ----------" << endl;

	return mese;
}


void Azienda::produzione() { //Legge i componenti necessari per la produzione
	for (int i = 0; i < ordiniP.size(); ++i) {
		vector<Componente> comp = ordiniP[i].getComp(); //vettore che contiene i componenti di ogni elettrodomestico da produrre

		for (int k = 0, k < comp.size(), ++k) {
			int id = comp[k].get_id();
			int quantita = comp[k].get_quantita();

			ricerca_comp(id, quantita);
		}
		
	}
}


bool Azienda::ricerca_comp(int id, int quantita) { //Controlla se ci sono i componenti necessari per produrre l'ordine

	for (int i = 0; i < magazzino.size(); ++i) {
		Componente comp = magazzino[i];

			if (id == comp.get_id() && quantita == comp.get_quantita()) return true;
			else ordina_comp(id, quantita);
	}
}