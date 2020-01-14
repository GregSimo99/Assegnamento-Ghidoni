//Gregori Simone

#include <iostream>
#include <fstream>
#include "header.h"
#include <string.h>

Azienda::Azienda(){}
Azienda::~Azienda(){}

void Azienda::lettura_componetsInfo(){
    ifstream file("componets_info.txt");
    if (file.is_open()) {
        cout<<endl<<"COMPONETS INFO"<<endl;
        while (file.good()) {                               //manca chiamata costrutturi
            int temp;
            file>>temp;
            cout<<"temp: "<<temp<<endl;
            string s;
            file>>s;
            cout<<"s: "<<s<<endl;
            int temp2;
            file>>temp2;
            cout<<"temp: "<<temp2<<endl;
            double d[3];
            for (int i=0; i<3; i++) {
                file>>d[i];
                cout<<"prezzo"<<i<<": "<<d[i]<<endl;
            }
            cout<<endl;
        }
		file.close();
    }
    else
        cout<<"Errore: file non trovato"<<endl;
}

void Azienda::lettura_elettrodomestici(){
    vector<string> ris;
    ifstream file("models.txt");
    string line;
    if (file.is_open()){
        while (getline(file,line)) {
            cout<<line<<endl;
            ris.push_back(line);
        }
        file.close();
    }
    else
        cout<<"Errore: file non trovato"<<endl;
    for (int i=0; i<ris.size(); i++) {
        ifstream file(ris[i]);
        if (file.is_open()) {
            int temp;
            file>>temp;
            //cout<<"temp: "<<temp<<endl;
            string s;
            file>>s;
            //cout<<"s: "<<s<<endl;
           
            while (file.good()) {                               //manca chiamata costrutturi
                cout<<endl<<"COMPONETI"<<endl;
                file>>temp;
                cout<<"temp: "<<temp<<endl;
                file>>s;
                cout<<"s: "<<s<<endl;
                file>>temp;
                cout<<"temp: "<<temp<<endl;
            }
            file.close();
        }
        else
            cout<<"Errore: file non trovato"<<endl;
    }
}

void Azienda::lettura_ordini(){
	ifstream file("orders.txt");							//CAMBIARE ESTENSIONE SU TUTTI!!
    if (file.is_open()) {
        cout<<endl<<"ORDINI"<<endl;
		int temp1;
		file>>temp1;
		cout<<"cassa: "<<temp1<<endl;
        while (file.good()) {                               //manca chiamata costrutturi
            int temp, temp2, temp3;
            file>>temp;
            cout<<"time_stamp: "<<temp<<endl;
            file>>temp2;
            cout<<"id: "<<temp2<<endl;
            file>>temp3;
            cout<<"quantity: "<<temp3<<endl<<endl;
            }
			file.close();
        }
		else
			cout<<"Errore: file non trovato"<<endl;
}

