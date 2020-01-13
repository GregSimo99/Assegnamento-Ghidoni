//Gregori Simone

#include <iostream>
#include <fstream>
#include "header.h"
#include <string.h>

Azienda::Azienda(){}
Azienda::~Azienda(){}

void Azienda::lettura_componetsInfo(){
    ifstream file("componets.dat");
    int temp;
    string s;
    double d[3];
    if (file.is_open()) {
        cout<<endl<<"COMPONETS INFO"<<endl;
        while (file.good()) {                               //manca chiamata costrutturi
            file>>temp;
            cout<<"temp: "<<temp<<endl;
            file>>s;
            cout<<"s: "<<s<<endl;
            file>>temp;
            cout<<"temp: "<<temp<<endl;
            for (int i=0; i<3; i++) {
                file>>d[i];
                cout<<"prezzo"<<i<<": "<<temp<<endl;
            }
        }
    }
    else
        cout<<"Errore: file non trovato"<<endl;
}

void Azienda::lettura_elettrodomestici(){
    vector<string> ris;
    ifstream file("models.dat");
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
        }
        else
            cout<<"Errore: file non trovato"<<endl;
    }
}

//helper function

/*
 int n = line.size();
            char s[n];   //forse è sbagliato
            strcpy(s, line.c_str());
            char* word;
            word = strtok(s, " ");      //riga senza gli spazi
    
            cout<<endl;
            while( word != nullptr ) {
                ris.push_back(word);
                word = strtok(nullptr, " ");
              }
 */

