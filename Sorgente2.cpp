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
		if (!ordiniP[i].stato_ordine()) //stato = false, ordine non ancora processato
		{
			Elettrodomestico el = ordiniP[i];
			vector<Componente> comp = el.getComp(); //vettore che contiene i componenti di ogni elettrodomestico da produrre
			int k = ordiniP[i].getQ(); //k contiene la quantità degli elettrodomestici da produrre

			bool produrre = true; //rimane vera se ci sono tutti i componenti necessari
			for (int j = 0, j < comp.size(), ++j)
			{
				int id = comp[j].get_id();
				int quantita = k*comp[j].get_quantita();

				bool esito = ricerca_comp(id, quantita); //true se trovato il componente, false altrimenti

				if (!esito) //se non è in magazzino è da ordinare
				{
					ordina_comp(id, quantita);
					evadere = false; //se manca un solo componente non si può evadere l'ordine
				}				
			}

			ordiniP[i].stato_ordine() = true; //ordine processato

			if (evadere) evasione_ordine(el.get_id()); //evasione dell'ordine se ci sono tutti i componenti necessari
		}
	}
}


bool Azienda::ricerca_comp(int id, int quantita) //controlla se ci sono i componenti necessari per produrre l'ordine
{ 

	for (int i = 0; i < magazzino.size(); ++i) 
	{

		Componente comp = magazzino[i]; //componenti del magazzino

		if (id == comp.get_id() && quantita <= comp.get_quantita())
		{
			if(quantita == comp.get_quantita()) comp.erase(comp.begin() + i); //se c'è  l'esatto numero di componenti nel magazzino, li elimino
			else comp.set_quantita(comp.get_quantita() - quantita); //sennò aggiorno la quantità
			
			return true;
		}

		return false
	}
}