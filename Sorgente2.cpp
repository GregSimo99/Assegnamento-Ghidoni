//Perini Mattia	  1162399

#include <iostream>
#include <stdlib.h>
#include "header.h"

using namespace std;


int Azienda::prox_mese() 
{
	++mese;
	_sleep(1500); //attesa di 1.5 secondi per simulare il trascorrere dei mesi
	cout << "----------  " << mese << "° mese  ----------" << endl;

	return mese;
}


void Azienda::produzione() //legge i componenti necessari per la produzione
{ 
	for (int i = 0; i < ordiniP.size(); ++i) 
	{
		if (!ordiniP[i].statoOrdine()) //stato = false, ordine non ancora processato (giusto?)
		{
			vector<Componente> comp = ordiniP[i].getComp(); //vettore che contiene i componenti di ogni elettrodomestico da produrre
			int k = ordiniP[i].getQ(); //k contiene la quantità degli elettrodomestici da produrre

			bool evadere = true;
			for (int j = 0, j < comp.size(), ++j)
			{
				int id = comp[j].get_id();
				int quantita = k*comp[j].get_quantita(); //k dipende dal numero di elettrodomestici da produrre

				bool esito = ricerca_comp(id, quantita); //true se trovato il componente, false altrimenti

				if (!esito) //se non è né in magazzino né in arrivo, da ordinare
				{
					ordina_comp(id, quantita);
					evadere = false; //se manca un solo componente non si può evadere l'ordine
				}				
			}

			bool ordiniP[i].statoOrdine() = true; //ordine processato (non mi ricordo bene a cosa serviva lo stato, è giusto qua e scritto così?)

			if (evadere) evasione_ordine(ordiniP[i].get_id()); //evasione dell'ordine se ci sono tutti i componenti necessari
		}
		
	}
}


bool Azienda::ricerca_comp(int id, int quantita) //controlla se ci sono i componenti necessari per produrre l'ordine
{ 

	for (int i = 0; i < magazzino.size(); ++i) 
	{

		Componente comp_mag = magazzino[i]; //componenti del magazzino
		Componente comp_arr = cAttesa[i]; //componenti in arrivo

		if (id == comp_mag.get_id() && quantita == comp_mag.get_quantita()) return true //componente trovato in magazzino
			
		else if (id == comp_arr.get_id() && quantita == comp_arr.get_quantita()) return true //componente in arrivo

		return false
	}
}