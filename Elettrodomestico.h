//Silvia Pasin  1189331

#ifndef ELETTRODOMESTICO_H
#define ELETTRODOMESTICO_H

#include <iostream>
#include <vector>
#include "Componente.h"
#include "Componente_richiesto.h"

class Elettrodomestico
{
public:
	Elettrodomestico() {}
	Elettrodomestico(int i, std::string n, double p, std::vector<Componente_richiesto>& comp, int q);
	~Elettrodomestico() {}

	int getId() const { return id; }
	std::string getNome() const { return nome; }
	double getPrice() const { return price; }
	void setQ(int n) { quantita = n; }
	int getQ() const { return quantita; }
	bool getStato() const { return stato; }
	void setStato(bool b) { stato = b; }
	std::vector<Componente_richiesto>& get_Comp() { return componenti; }

private:
	int id, quantita;
	std::vector<Componente_richiesto> componenti;
	std::string nome;
	double price;           //letto da file
	bool stato = false;
};

#endif //!ELETTRODOMESTICO_H