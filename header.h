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
    double price;
};

class Azienda
{
public:
    Azienda();
    ~Azienda();

    //funzioni per leggere i dati
    void lettura_elettrodomestici();
private:
    int cassa, mese;
    vector<Elettrodomestico> catalogo;
    vector<Elettrodomestico> ordini;
    vector<Componente> magazzino;
    vector<Componente> cAttesa;
};
