//Silvia Pasin  1189331

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "header.h"
void Azienda::current_state()
{
	//stampa componenti in arrivo
	std::cout << "Componenti acquistati ma non ancora arrivati: " << '\n';
	for (int i = 0; i < cAttesa.size(); i++)
	{
		Componente c = cAttesa[i];
		std::string s = to_string(c.get_id()) + ", " + c.get_nome() +": " + to_string(c.get_quantita());
		std::cout << s << '\n';
	}

	//stampa magazzino
	std::cout << "Componenti presenti in magazzino: " << '\n';
	for (int i = 0; i < magazzino.size(); i++)
	{
		Componente c = magazzino[i];
		std::string s = to_string(c.get_id()) + ", " + c.get_nome() + ": " + to_string(c.get_quantita());
		std::cout << s << '\n';
	}	

	//stampa ordini evasi
	std::cout << "Ordini evasi: " << '\n';
	for (int i = 0; i < evasi.size(); i++)
	{
		Ordine e = evasi[i];
		std::string s = to_string(e.getId()) + ": " + to_string(e.getQ());
		std::cout << s << '\n';
	}
}
void Azienda::controllo_arrivi() //scansiono il vettore dei componenti in arrivo e se sono arrivati aggiorno il magazzino
{
	for (int i = 0; i < cAttesa.size(); i++)
	{
		Componente c = cAttesa[i];
		if (c.get_arrivo() == mese)
		{
			int p = trova_Componente(c.get_id(), magazzino);
			Componente m = magazzino[p];
			m.set_quantita(m.get_quantita() + c.get_quantita());
			cAttesa.erase(cAttesa.begin() + i);
		}			
	}
}

bool cmp(Ordine a, Ordine b)
{
	return a.getTs() < b.getTs();
}
void Azienda::lista_attesaOrdini() //ordina vettore ordini secondo timestamp
{
	sort(ordini.begin(), ordini.end(), cmp);
}

int trova_Elettrodomestico(int id, const vector<Elettrodomestico>& e)
{
	for (int i = 0; i < e.size(); i++) {
			if (e[i].getId() == id)
				return i;
		}
		return -1;
}

//funzione che cerca nel vettore ordini quelli con time_stamp = al mese e li carica come elettrodomestico (cercando l'id in catalogo) in ordiniP
void Azienda::commissione_ordini()
{
	//vettore ordini già ordinato secondo time_stamp
	int i = 0;
	std::vector<Elettrodomestico> v;
	while(ordini[i].getTs()==mese)
	{
		Ordine o = ordini[i];
		int j = trova_Elettrodomestico(o.getId(), catalogo);
		Elettrodomestico e = catalogo[j];
		v(0);                      //sommo ordini dello stesso elettrodomestico (e con stesso time_stamp)
		int t = 0;
		int k = trova_Elettrodomestico(o.getId(), v);
		if (k == -1)
		{
			v.push_back(e);
			v[t].setQ(o.getQ());
			t++;
		}
		else
		{
			v[k].setQ(v[k].getQ() + o.getQ());
		}
		ordini.erase(ordini.begin() + i); //cancello da ordini quelli che ho messo in ordiniP?
		i++;
	}
	for (int i = 0; i < v.size(); i++)
		ordiniP.push_back(v[i]);
}

bool Azienda::ordina_comp(int id, int quantita)
{
	int p = trova_Componente(id, magazzino);
	Componente c = magazzino[p];
	double* prices = c.getPrice();
	double price = 0;
	if (quantita >= 0 && quantita <= 10)
		price = prices[0];
	else if(quantita >= 11 && quantita <= 50)
		price = prices[1];
	else if(quantita >= 51)
		price = prices[2];
	if (price * quantita <= cassa)
	{
		cAttesa.push_back(c);
		cAttesa.back().setArrivo(c.getD_time() + mese);
		cassa = cassa - price * quantita;
		return true;
	}
	else return false;
}