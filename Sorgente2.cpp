//Perini Mattia	  1162399

#include <iostream>
#include <stdlib.h>
#include "header.h"

using namespace std;


int Azienda::prox_mese() 
{
	++mese;
	_sleep(1500); //attesa di 1.5 secondi per simulare il trascorrere dei mesi
	cout << "----------  " << mese << "� mese  ----------" << endl;

	return mese;
}


void Azienda::produzione() //legge i componenti necessari per la produzione
{ 
	for (int i = 0; i < ordiniP.size(); i++)
	{
		Elettrodomestico& el = ordiniP[i];
		if (el.getStato()) //se � stato prodotto l'elettrodomestico
		{
			evasi.push_back(Ordine(el.getId(), 0, el.getQ(), 0));
			ordiniP.erase(ordiniP.begin() + i);
		}

		else //ordine non ancora processato
		{
			vector<Componente_richiesto>& comp = el.getComp(); //vettore che contiene i componenti di ogni elettrodomestico da produrre
			int k = el.getQ(); //k contiene la quantit� degli elettrodomestici da produrre

			bool evadere = true;
			for (int j = 0, j < comp.size(), j++)
			{
				int id = comp[j].get_id();
				int quantita = k * comp[j].get_quantita();

				bool esito = ricerca_comp(id, quantita); //true se trovato il componente, false altrimenti

				if (!esito) //se non � in magazzino � da ordinare
				{
					if (!comp[j].getStato())
					{
						bool ordinato = ordina_comp(id, quantita);
						if (ordinato) comp[j].setStato(true);
					}
					evadere = false; //se manca un solo componente non si pu� evadere l'ordine
					
				}				
			}
			if (evadere)
			{
				e.setStato(true);
				for (int i = 0; i < comp.size[]; i++) tolgo_magazzino(comp[i].get_id(), k * comp[i].get_quantita());
			}

			ordiniP[i].stato_ordine() = true; //ordine processato

			if (evadere) evasione_ordine(el.get_id()); //evasione dell'ordine se ci sono tutti i componenti necessari
		}
	}
}


bool Azienda::ricerca_comp(int id, int quantita) //controlla se ci sono i componenti necessari per produrre l'ordine
{ 

	for (int i = 0; i < magazzino.size(); i++)
	{

		Componente comp = magazzino[i]; //componenti del magazzino

		if (id == comp.get_id() && quantita <= comp.get_quantita())
		{
			if(quantita == comp.get_quantita()) comp.erase(comp.begin() + i); //se c'�  l'esatto numero di componenti nel magazzino, li elimino
			else comp.set_quantita(comp.get_quantita() - quantita); //senn� aggiorno la quantit�
			
			return true;
		}

		return false
	}
}