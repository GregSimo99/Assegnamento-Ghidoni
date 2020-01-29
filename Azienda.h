//Perini Mattia 1162399

#ifndef AZIENDA_H
#define AZIENDA_H

#include <iostream>
#include <vector>
#include "Componente.h"
#include "Componente_richiesto.h"
#include "Elettrodomestico.h"
#include "Ordine.h"

class Azienda
{
public:
	Azienda();
	~Azienda();

	//funzioni per leggere i dati
	void lettura_elettrodomestici();   //CONTROLLARE Componente_richiesto IN sorgente1.cpp
	void lettura_componentsInfo();
	void lettura_ordini();

	void current_state();             //funzione che stampa stato corrente
	void lista_attesaOrdini();		  //funzione che ordina gli ordini in base al time_stamp
	void controllo_arrivi();          //funzione che sposta componente arrivato da cAttesa a magazzino
	void commissione_ordini();		  //funzione che cerca nel vettore ordini quelli con time_stamp = al mese e li carica come elettrodomestico (cercando l'id in catalogo ) e che inizializza arrivo
	bool ordina_comp(int id, int quantita); //funzione che ordina il componente (ritorna true se è stato ordinato, false altrimenti)
	void produzione();
	bool ricerca_comp(int id, int quantita) const;	//funzione che controlla se ci sono i componenti in magazzino per produrlo
	void tolgo_magazzino(int id, int quantita);	//funzione che diminuisce la quantita nel magazzino di un certo componente
	void calcola_guadagno(int idE, int quantita); //funzione che calcola il guadagno e aggiorna la cassa
	bool altri_ordini();
	int prox_mese();
	void stampa_mese();

private:
	int cassa, mese, totOrdini;
	std::vector<Elettrodomestico> catalogo;
	std::vector<Elettrodomestico> ordiniP; //ordini in produzione così posso sommare ordini di elettrodomestici uguali
	std::vector<Ordine> ordini;
	std::vector<Componente> magazzino;
	std::vector<Componente> cAttesa; //componenti in arrivo
	std::vector<Ordine> evasi;
};

//helper function

int trova_Componente(int id, const std::vector<Componente>& c);	//trova componente su array magazzino. const?
int trova_Elettrodomestico(int id, const std::vector<Elettrodomestico>& e);
bool cmp(Ordine a, Ordine b);

#endif //!AZIENDA_H