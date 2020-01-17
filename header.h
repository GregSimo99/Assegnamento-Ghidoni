#include<iostream>
#include<vector>

using namespace std;

class Componente
{
public:
    Componente(){}
    ~Componente(){}
    //get e set se servono
    int get_id() const { return id; }
    int get_quantita() const { return quantita; }
    string get_nome() const { return nome; }
    int get_arrivo() const { return arrivo; }
    void set_quantita(int n) { quantita = n; }
    bool operator ==(Componente a) { return id == a.id; }

private:
    int id, d_time, quantita, arrivo;
    std::string nome;
    double price[];
};

class Elettrodomestico
{
public:
    Elettrodomestico(){}
    ~Elettrodomestico(){}
    int get_id() const { return id; }
    int get_quantita() const { return quantita; }
    string get_nome() const { return nome; }
    int get_timestamp() const { return time_stamp; }
    //vector<Componente> get_componenti() { return componenti; }
private:
    int id, time_stamp, stato, quantita;
    std::vector<Componente> componenti;
    std::string nome;
    double price;           //da calcolare sommando tutti i componeti? oppure leggendolo dal file?
};

class Azienda
{
public:
    Azienda();
    ~Azienda();

    void current_state();
    void controllo_arrivi();
    //funzioni per leggere i dati
    void lettura_elettrodomestici();
    void lettura_componetsInfo();
	void lettura_ordini();
	bool is_componente();
	bool is_elettrodomestico();
private:
    int cassa, mese;
    vector<Elettrodomestico> catalogo;
    vector<Elettrodomestico> ordini;
    vector<Componente> magazzino;
    vector<Componente> cAttesa;
    vector<Elettrodomestico> evasi;
    //vector<string> ris;
};

//helper function
void lettura_models();      //devo avere unu vettore di stringhe da passare per indirizzo
