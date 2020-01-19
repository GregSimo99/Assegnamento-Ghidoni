//Gregori Simone	1201534

#include <iostream>
#include <fstream>
#include "header.h"
#include <string.h>

//costruttori

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

Elettrodomestico::Elettrodomestico(int i, string n, double p, vector<Componente> &comp){
	id = i;
	nome = n;
	price = p;
	componenti = comp;
}

//Elettrodomestico::Elettrodomestico(): id{0}, nome{""}, price{0}, componenti(nullptr){};

Ordine::Ordine(int i, int ts, int q, int s){
	id = i;
	time_stamp = ts;
	quantita = q;
	stato = s;
}

void Ordine::setStato(int s){
	if(s>=0 && s<=2)
		stato = s;
	else
		cout<<"Errore: identificativo stato non previsto"<<endl;
}

Azienda::Azienda(){
	lettura_componentsInfo();
	lettura_elettrodomestici();
	lettura_ordini();
}
Azienda::~Azienda(){}

void Azienda::lettura_componentsInfo(){
    ifstream file("components_info.txt");
    if (file.is_open()) {
        cout<<endl<<"COMPONENTS INFO"<<endl;
        while (file.good()) {
            int id;
            file>>id;
            cout<<"id: "<<id<<endl;
            string s;
            file>>s;
            cout<<"s: "<<s<<endl;
            int dtime;
            file>>dtime;
            cout<<"dtime: "<<dtime<<endl;
            double d[3];
            for (int i=0; i<3; i++) {
                file>>d[i];
                cout<<"prezzo"<<i<<": "<<d[i]<<endl;
            }
            cout<<endl;
			magazzino.push_back(Componente(id, dtime, s, d,0,-1));		//arrivo inizializzato a -1
        }
		
		file.close();
    }
    else
        cout<<"Errore: file non trovato"<<endl;
}

void Azienda::lettura_elettrodomestici(){
    vector<string> ris;
    ifstream file("models.txt");
    string line;
    if (file.is_open()){
        while (getline(file,line)) {
            cout<<line<<endl;
            ris.push_back(line);
        }
        file.close();
    }
    else
        cout<<"Errore: file non trovato"<<endl;
    for (int i=0; i<ris.size(); i++) {
        ifstream file(ris[i]);
        if (file.is_open()) {
			vector<Componente> comp;
            int iE,iC,q;
			double p;
			string nE,nC;
            file>>iE;
            //cout<<"iE: "<<iE<<endl;
            file>>nE;
            //cout<<"nE: "<<nE<<endl;
			file>>p;
			//cout<<"p: "<<p<<endl;
			
			while (file.good()) {                               //manca chiamata costrutturi
                cout<<endl<<"COMPONENTI"<<endl;
                file>>iC;
                cout<<"ic: "<<iC<<endl;
                file>>nC;
                cout<<"nC: "<<nC<<endl;
                file>>q;
                cout<<"q: "<<q<<endl;
				//trova componete per mese e prezzo
				int pos = trova_Componente(iC, magazzino);
				if (pos!=-1) {
					comp.push_back(Componente(iC, magazzino[pos].getD_time(), nC, magazzino[pos].getPrice(), q, -1));
				}
				else
					cout<<"Errore: componente non trovato"<<endl;
            }
			cout<<"-----> id: "<<iE<<endl;
			catalogo.push_back(Elettrodomestico(iE, nE, p, comp));
            file.close();
        }
        else
            cout<<"Errore: file non trovato"<<endl;
    }
}

void Azienda::lettura_ordini(){
	ifstream file("orders.txt");							//CAMBIARE ESTENSIONE SU TUTTI!!
    if (file.is_open()) {
        cout<<endl<<"ORDINI"<<endl;
		int c = 0, ts = 0, iO = 0, q = 0;
		file>>c;
		cout<<"cassa: "<<c<<endl;
		cassa = c;											//inizializzazione cassa
        while (file.good()) {                              
            
            file>>ts;
            cout<<"time_stamp: "<<ts<<endl;
            file>>iO;
            cout<<"id: "<<iO<<endl;
            file>>q;
            cout<<"quantity: "<<q<<endl<<endl;
            }
			ordini.push_back(Ordine(iO, ts, q, 0));			//serve lo stato?
			
			file.close();
        }
		else
			cout<<"Errore: file non trovato"<<endl;
}

//helper funcion

int trova_Componente(int id, const vector<Componente> &c){
	for (int i = 0; i<c.size(); i++) {
		if (c[i].get_id()==id) 
			return i;
	}
	return -1;
}
