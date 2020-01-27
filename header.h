#ifndef HEADER_H
#define HEADER_H	

#include<iostream>
#include<vector>

class Componente
{
public:
	Componente();
	Componente(int i, int time, std::string n, double *p, int q, int a);
	~Componente() {}
    int get_id() const { return id; }
	int get_quantita() const { return quantita; }
	std::string get_nome() const { return nome; }
	int get_arrivo() const { return arrivo; }
	void set_quantita(int n) { quantita = n; }
	void setArrivo(int a) {arrivo = a;}
	int getD_time() const {return d_time;}
	double* getPrice() {return price;}
	
private:
    int id, d_time, quantita, arrivo;
    std::string nome;
    double price[3];
};

class Componente_richiesto
{
public:
	Componente_richiesto(int i, std::string n, int q); 
	bool getStato() const { return stato; }
	void setStato(bool b) { stato = b; }
	int getId() const { return id; }
	int getQ() const { return quantita; }
private:
	int id, quantita;
	std::string nome;
	bool stato = false; //true ordinato, false non ordinato
};

class Elettrodomestico
{
public:
	Elettrodomestico(){};
	Elettrodomestico(int i, std::string n, double p, std::vector<Componente_richiesto>& comp, int q);
    ~Elettrodomestico(){}
	
	int getId() const {return id;}
	std::string getNome() const {return nome;}
	double getPrice() const {return price;}
	void setQ(int n) { quantita = n; }
	int getQ() const { return quantita; }
	bool getStato() const { return stato; }
	void setStato(bool b) { stato = b; }
	std::vector<Componente_richiesto>& get_Comp() { return componenti; }	//con o senza reference?

private:											 
    int id, quantita;
    std::vector<Componente_richiesto> componenti;
    std::string nome;
    double price;           //letto da file
	bool stato = false; 
};

class Ordine
{
public:
	Ordine(){}
	Ordine(int i, int ts, int q);
	~Ordine(){};
	int getTs() const{return time_stamp;}
	int getQ() const{return quantita;}
	int getId() const{return id;}
private:
	int time_stamp, quantita, id;
};

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
	void calcola_guadagno(int idE, int quantita);				//funzione che calcola il guadagno e aggiorna la cassa
	bool altri_ordini();
	int prox_mese();
	
private:										
    int cassa, mese, totOrdini;
    std::vector<Elettrodomestico> catalogo;
	std::vector<Elettrodomestico> ordiniP;				//ordini in produzione così posso sommare ordini di elettrodomestici uguali
	std::vector<Ordine> ordini;
	std::vector<Componente> magazzino;
	std::vector<Componente> cAttesa;    //componenti in arrivo
	std::vector<Ordine> evasi;
};

//helper function

int trova_Componente(int id, const std::vector<Componente> &c);	//trova componente su array magazzino. const?
int trova_Elettrodomestico(int id, const std::vector<Elettrodomestico>& e);
bool cmp(Ordine a, Ordine b);

#endif // !HEADER_H

