//Perini Mattia 1162399

#ifndef ORDINE_H
#define ORDINE_H

#include <iostream>
#include <vector>
#include "Componente.h"
#include "Componente_richiesto.h"
#include "Elettrodomestico.h"

class Ordine
{
public:
	Ordine() {}
	Ordine(int i, int ts, int q);
	~Ordine() {};
	int getTs() const { return time_stamp; }
	int getQ() const { return quantita; }
	int getId() const { return id; }
private:
	int time_stamp, quantita, id;
};

#endif //!ORDINE_H