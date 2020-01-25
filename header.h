#include<iostream>
#include<vector>

using namespace std;

class Componente
{
public:
	Componente();
	Componente(int i, int time, string n, double *p, int q, int a);
	~Componente(){}
    int get_id() const { return id; }
	int get_quantita() const { return quantita; }
	string get_nome() const { return nome; }
	int get_arrivo() const { return arrivo; }
	void set_quantita(int n) { quantita = n; }
	//bool operator ==(Componente a) { return id == a.id; }
	void setArrivo(int a) {arrivo = a;}
	int getD_time() const {return d_time;}
	double* getPrice() {return price;}
	
private:
    int id, d_time, quantita, arrivo;
    string nome;
    double price[3];
};

class Componente_richiesto
{
public:
	Componente_richiesto(int i, string n, int q);
private:
	int id, quantita;
	string nome;
};

class Elettrodomestico
{
public:
	Elettrodomestico(){};
	Elettrodomestico(int i, string n, double p, vector<Componente_richiesto> &comp, int q); //CAMBIARE DEFINIZIONE IN sorgente1.cpp
    ~Elettrodomestico(){}
	
	int getId() const {return id;}
	string getNome() const {return nome;}
	double getPrice() const {return price;}
	void setQ(int n) { quantita = n; }
	int getQ() const { return quantita; }
	//vector<Componente_richiesto>& getComp() const { return componenti; }

private:											 
    int id, quantita;
    vector<Componente_richiesto> componenti;
    string nome;
    double price;           //letto da file
};

class Ordine
{
public:
	Ordine(){}
	Ordine(int i, int ts, int q, int s);
	~Ordine(){};
	int getTs() const{return time_stamp;}
	int getQ() const{return quantita;}
	int getS() const{return stato;}
	int getId() const{return id;}
	void setStato(int s);
private:
	int time_stamp, stato, quantita, id;
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
	bool ricerca_comp(int id, int quantita);	//funzione che controlla se ci sono i componenti in magazzino per produrlo
	
private:										
    int cassa, mese;
    vector<Elettrodomestico> catalogo;
	vector<Elettrodomestico> ordiniP;				//ordini in produzione così posso sommare ordini di elettrodomestici uguali
    vector<Ordine> ordini;
    vector<Componente> magazzino;
    vector<Componente> cAttesa;    //componenti in arrivo
	vector<Ordine> evasi;
};

//helper function

int trova_Componente(int id, const vector<Componente> &c);	//trova componente su array magazzino. const?
int trova_Elettrodomestico(int id, const vector<Elettrodomestico>& e);
bool cmp(Ordine a, Ordine b);
