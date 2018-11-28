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

int main(void) {
    string fileName;
    int zz = 0 ;
    int choosen = 0;
    cout<<"Witamy w naszym magazynie ubran"<<endl;
    cout<<"Wczytaj plik ze stanem magazynu. Podaj nazwie pliku z rozszerzeniem .txt :"<<endl;
    cin>>fileName;
    Place ourStorage(fileName);
    ourStorage.readFromFile();
    
    while (zz < 25) {
        cout<<endl<<"---------- W celu dokonia zmian wybierz jedna z ponizszych opcji: ---------------"<<endl;
        cout<<"1 --> wyswietl elementy na ekranie"<<endl;
        cout<<"2 --> usun element"<<endl;
        cout<<"3 --> dodaj element"<<endl;
        cout<<"4 --> zapisz zmiany do pliku wejsciowego: "<<fileName<<endl;
        cout<<"9 --> zamknij system"<<endl<<endl;
        cin>>choosen;
        if (choosen == 1)
            ourStorage.printOnScreen();
        else if (choosen == 2) ourStorage.removeCloth();
        else if (choosen == 3) ourStorage.addElement();
        else if (choosen == 4) ourStorage.saveToFile();
        else if (choosen == 9) break;
        ++zz;
    }
    return 0;
}
