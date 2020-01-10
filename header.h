#include<iostream>
#include<vector>

class Componente
{
public:
	Componente();
	~Componente();
	//get e set se servono
private:
	int id, d_time, quantita, arrivo;
	std::string nome;
	double[] price;
};

class Elettrodomestico
{
public:
	Elettrodomestico();
	~Elettrodomestico();

private:
	int id, time_stamp, stato, quantita;
	std::vector<Componente> componenti;
	std::string nome;
	double price;
};

