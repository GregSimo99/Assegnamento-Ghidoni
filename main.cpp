
#include <iostream>
#include "header.h"

using namespace std;

int main() {
    Azienda a{};
	
	a.lista_attesaOrdini();
	std::cout<<"Mese 0"<<std::endl;
	while (a.altri_ordini()) {		//ciclo termina quanto stati venduti tutti gli ordini
		a.stampa_mese();
		a.commissione_ordini();
		a.controllo_arrivi();
		a.produzione();
		
		a.current_state();
		string s;
		cout<<"Per avanzare di un mese premi un tasto: ";
		cin>>s;
		if(s!="")
			a.prox_mese();
	}
    return 0;
}
