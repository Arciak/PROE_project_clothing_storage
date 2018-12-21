//
//  main.cpp
//  clothingStorage
//
//  Created by Mac Artur on 17/11/2018.
//  Copyright © 2018 Mac Artur. All rights reserved.
//

#include <iostream>
#include "cloth.hpp"
#include "storage.hpp"
#include "place.hpp"


enum operacja {
    wyswietl = 1,
    usunElement = 2,
    dodajElement = 3,
    zapiszPlik = 4,
    zamknij = 9
};

int main(void) {
    string fileName;
    int zz = 0 ;
    int choosen = 0;
    cout<<"Witamy w naszym magazynie ubran"<<endl;
    cout<<"Wczytaj plik ze stanem magazynu. Podaj nazwie pliku z rozszerzeniem .txt :"<<endl;
    cin>>fileName;
    char * fileName_ = new char [fileName.length()+1];
    strcpy (fileName_, fileName.c_str());
    Place ourStorage(fileName_);
    ourStorage.readFromFile();
    
    while (zz < 25) {
        cout<<endl<<"---------- W celu dokonia zmian wybierz jedna z ponizszych opcji: ---------------"<<endl;
        cout<<"1 --> wyswietl elementy na ekranie"<<endl;
        cout<<"2 --> usun element"<<endl;
        cout<<"3 --> dodaj element"<<endl;
        cout<<"4 --> zapisz zmiany do pliku wejsciowego: "<<fileName<<endl;
        cout<<"9 --> zamknij system"<<endl<<endl;
        cin>>choosen;
        switch (choosen) {
            case wyswietl:
                ourStorage.printOnScreen();
                break;
            case usunElement:
                ourStorage.removeCloth();
                break;
            case dodajElement:
                ourStorage.addElement();
                break;
            case zapiszPlik:
                ourStorage.saveToFile();
                break;
            case zamknij:
                zz = 24;
                break;
            default:
                break;
        }
        ++zz;
    }
    return 0;
}
