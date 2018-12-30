//
//  helpers.hpp
//  clothingStorage
//
//  Created by Mac Artur on 29.12.2018.
//  Copyright © 2018 Mac Artur. All rights reserved.
//

#ifndef helpers_hpp
#define helpers_hpp

#include <stdio.h>
#include "storage.hpp"
#include "Shirt.hpp"

void welcomeScreen(void){
    cout<<"-------------------------------------------------------------------------------------"<<endl;
    cout<<"Witamy w magazynie ubran :) "<<endl;
    cout<<"Ponizej znajduje sie manu naszej aplikacji prosimy o wybranie jednej z opcji."<<endl;
    cout<<"-------------------------------------------------------------------------------------"<<endl<<endl;
}

void menuScreen(string fileName){
    cout<<endl<<"---------- W celu dokonia zmian wybierz jedna z ponizszych opcji: ---------------"<<endl;
    cout<<"1 --> wczytaj plik"<<endl;
    cout<<"2 --> wyswietl elementy na ekranie"<<endl;
    cout<<"3 --> usun element"<<endl;
    cout<<"4 --> dodaj element"<<endl;
    cout<<"5 --> zapisz zmiany do pliku wejsciowego: "<<fileName<<endl;
    cout<<"9 --> zamknij system"<<endl<<endl;
}

void wczytajCeny(shared_ptr<Storage>& sklad){
    
}

void dodajUbranie(shared_ptr<Storage>& sklad){
    unsigned int tempChoose = 0;
    double cena = 0.0;
    string rozmiar = "Na/Na";
    double dlugosc = 0.0;
    double szerokosc = 0.0;
    double dlugoscRekawa = 0.0;
    double obwodKolnierza = 0.0;
    
    cout<<"Wybierz element do dodania"<<endl;
    cout<<"1--> Koszulka"<<endl;
    cout<<"2--> Long-sleeve"<<endl;
    cout<<"3--> Koszula"<<endl;
    cin>>tempChoose;
        cout<<"Podaj cene (double): ";
        cin>>cena;
        cout<<"Podaj rozmiar (string): ";
        cin>>rozmiar;
        cout<<"Podaj dlugosc (double): ";
        cin>>dlugosc;
        cout<<"Podaj szerokosc (double): ";
        cin>>szerokosc;
    auto ciuszek = make_shared<Tshirt>(cena, rozmiar, dlugosc, szerokosc);
    sklad->addCloth(ciuszek);
}


enum operacja {
    plik = 1,
    wyswietl = 2,
    usunElement = 3,
    dodajElement = 4,
    zapiszPlik = 5,
    zamknij = 9
};


#endif /* helpers_hpp */
