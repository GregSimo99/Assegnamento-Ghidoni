//Silvia Pasin

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
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
		Elettrodomestico e = evasi[i];
		std::string s = to_string(e.get_id()) + ", " + e.get_nome() + ": " + to_string(e.get_quantita());
		std::cout << s << '\n';
	}
}
void Azienda::controllo_arrivi() //scansiono il vettore dei componenenti in arrivo e se sono arrivati aggiorno il magazzino
{
	for (int i = 0; i < cAttesa.size(); i++)
	{
		Componente c = cAttesa[i];
		if (c.get_arrivo() == mese)
		{
		    vector<Componente>::iterator p = std::find(magazzino.begin(), magazzino.end(), c);
			(*p).set_quantita((*p).get_quantita() + c.get_quantita());
			cAttesa.erase(cAttesa.begin() + i);
		}			
	}
}

