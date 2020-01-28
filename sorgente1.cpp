//Gregori Simone	1201534

#include <iostream>
#include <fstream>
#include "header.h"
#include <string.h>

//costruttori
using namespace std;

Componente::Componente(int i, int time, string n, double *p, int q, int a){
	id = i;
	d_time = time;
	nome = n;
	for (int i=0; i<3; i++) {												
		price[i]=p[i];
	}
	quantita = q;
	arrivo = a;
}

Elettrodomestico::Elettrodomestico(int i, string n, double p, vector<Componente_richiesto> &comp, int q){
	id = i;
	nome = n;
	price = p;
	componenti = comp;
	quantita = q;
}


Ordine::Ordine(int i, int ts, int q){
	id = i;
	time_stamp = ts;
	quantita = q;
}

Componente_richiesto::Componente_richiesto(int i, string n, int q){
	id = i;
	nome = n;
	quantita = q;
}

Azienda::Azienda(){
	mese = 0;
	lettura_componentsInfo();
	lettura_elettrodomestici();
	lettura_ordini();
	totOrdini = ordini.size();
}
Azienda::~Azienda(){}

void Azienda::lettura_componentsInfo(){
    ifstream file("componets_info.dat");
    if (file.is_open()) {
        while (file.good()) {
            int id;
            file>>id;
            string s;
            file>>s;
            int dtime;
            file>>dtime;
            double d[3];
            for (int i=0; i<3; i++) {
                file>>d[i];
            }
			magazzino.push_back(Componente(id, dtime, s, d,0,-1));		//arrivo inizializzato a -1
        }
		
		file.close();
    }
    else
        cout<<"Errore: file non trovato"<<endl;
}

void Azienda::lettura_elettrodomestici(){
    vector<string> ris;
    ifstream file("models.dat");
    string line;
    if (file.is_open()){
        while (getline(file,line)) {
            ris.push_back(line);
        }
        file.close();
    }
    else
        cout<<"Errore: file non trovato"<<endl;
    for (int i=0; i<ris.size(); i++) {
        ifstream file(ris[i]);
        if (file.is_open()) {
			vector<Componente_richiesto> comp;
            int iE,iC,q;
			double p;
			string nE,nC;
            file>>iE;
            file>>nE;
			file>>p;
			
			while (file.good()) {                               //manca chiamata costrutturi
                file>>iC;
                file>>nC;
                file>>q;
				comp.push_back(Componente_richiesto{iC, nC, q});
            }
			catalogo.push_back(Elettrodomestico(iE, nE, p, comp, 0));		//quantità inizializza a 0 su catalogo
            file.close();
        }
        else
            cout<<"Errore: file non trovato"<<endl;
    }
}

void Azienda::lettura_ordini(){
	ifstream file("orders.dat");							//CAMBIARE ESTENSIONE SU TUTTI!!
    if (file.is_open()) {
		int c = 0, ts = 0, iO = 0, q = 0;
		file>>c;
		cassa = c;											//inizializzazione cassa
        while (file.good()) {                              
            file>>ts;
            file>>iO;
            file>>q;
			ordini.push_back(Ordine(iO, ts, q));			//serve lo stato?
            }
			
			file.close();
        }
		else
			cout<<"Errore: file non trovato"<<endl;
}

void Azienda::tolgo_magazzino(int id, int quantita){
	for (int i = 0; i<magazzino.size(); i++) {
		if (magazzino[i].get_id()==id) {
			int q = magazzino[i].get_quantita() - quantita;
			magazzino[i].set_quantita(q);
		}
	}
}

void Azienda::calcola_guadagno(int idE, int q) { 	//calcola guadagno ed aggiorna cassa
	int pVendita = 0;
	int pos = trova_Elettrodomestico(idE, catalogo);
	pVendita = catalogo[pos].getPrice();			//leggo prezzo di vendita
	
	cassa = cassa+pVendita*q;
	
}

//helper funcion

int trova_Componente(int id, const vector<Componente> &c) {
	for (int i = 0; i<c.size(); i++) {
		if (c[i].get_id()==id) 
			return i;
	}
	return -1;
}

bool Azienda::altri_ordini(){
	if (totOrdini==evasi.size()) 
		return false;
	else
		return true;
}
