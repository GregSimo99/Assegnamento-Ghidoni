#include<iostream>
#include<vector>

using namespace std;

class Componente
{
public:
    Componente(){}
    ~Componente(){}
    //get e set se servono
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

    //funzioni per leggere i dati
    void lettura_elettrodomestici();
    void lettura_componetsInfo();
private:
    int cassa, mese;
    vector<Elettrodomestico> catalogo;
    vector<Elettrodomestico> ordini;
    vector<Componente> magazzino;
    vector<Componente> cAttesa;
    //vector<string> ris;
};

//helper function
void lettura_models();      //devo avere unu vettore di stringhe da passare per indirizzo
