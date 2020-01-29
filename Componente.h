//Gregori Simone	1201534

#ifndef COMPONENTE_H
#define COMPONENTE_H
#include <iostream>
#include <vector>

class Componente
{
public:
	Componente();
	Componente(int i, int time, std::string n, double* p, int q, int a);
	~Componente() {}
	int get_id() const { return id; }
	int get_quantita() const { return quantita; }
	std::string get_nome() const { return nome; }
	int get_arrivo() const { return arrivo; }
	void set_quantita(int n) { quantita = n; }
	void setArrivo(int a) { arrivo = a; }
	int getD_time() const { return d_time; }
	double* getPrice() { return price; }

private:
	int id, d_time, quantita, arrivo;
	std::string nome;
	double price[3];
};

#endif //!COMPONENTE_H