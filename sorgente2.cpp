//Perini Mattia	  1162399

#include <iostream>
#include "header.h"

using namespace std;

int Azienda::prox_mese()
{
	++mese;
	return mese;
}


void Azienda::produzione() //legge i componenti necessari per la produzione
{
	int i = 0;
	while (i < ordiniP.size()) {
		Elettrodomestico el;
		el = ordiniP[i];
		if (el.getStato()) //se è stato prodotto l'elettrodomestico
		{
			evasi.push_back(Ordine(el.getId(), 0, el.getQ()));
			ordiniP.erase(ordiniP.begin() + i);
		}

		else //ordine non ancora processato
		{
			vector<Componente_richiesto>& comp = ordiniP[i].get_Comp(); //vettore che contiene i componenti di ogni elettrodomestico da produrre
			int k = el.getQ(); //k contiene la quantità degli elettrodomestici da produrre

			bool evadere = true;
			for (int j = 0; j < comp.size(); j++)
			{
				int id = comp[j].getId();
				int quantita = k * comp[j].getQ();

				bool esito = ricerca_comp(id, quantita); //true se trovato il componente, false altrimenti

				if (!esito) //se non è in magazzino è da ordinare
				{
					if (!comp[j].getStato())
					{
						bool ordinato = ordina_comp(id, quantita);
						if (ordinato) comp[j].setStato(true);
					}
					evadere = false; //se manca un solo componente non si può evadere l'ordine					
				}
			}

			if (evadere)
			{
				ordiniP[i].setStato(true);
				for (int i = 0; i < comp.size(); i++) tolgo_magazzino(comp[i].getId(), k * comp[i].getQ());
			}
			i++;
		}
	}
}


bool Azienda::ricerca_comp(int id, int quantita) const //controlla se ci sono i componenti necessari per produrre l'ordine
{

	for (int i = 0; i < magazzino.size(); i++)
	{

		Componente comp = magazzino[i]; //componenti del magazzino

		if (id == comp.get_id() && quantita <= comp.get_quantita())	return true;


	}
	return false;
}

void Azienda::stampa_mese() {
	cout << "----------  " << mese << "° mese  ----------" << endl;
}