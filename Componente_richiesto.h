#ifndef COMPONENTE_RICHIESTO_H
#define COMPONENTE_RICHIESTO_H

#include <iostream>
#include <vector>
#include "Componente.h"

class Componente_richiesto : public Componente
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

#endif //!COMPONENTE_RICHIESTO_H