//
//  main.cpp
//  clothingStorage
//
//  Created by Mac Artur on 17/11/2018.
//  Copyright © 2018 Mac Artur. All rights reserved.
//

#include "cloth.hpp"
#include "storage.hpp"
#include "place.hpp"
#include "helpers.hpp"
#include "Tshirt.hpp"
int main(void) {
    int zz = 0 ;
    int choosen = 0;
    
    string fileName = "temp.txt";
    welcomeScreen();
  
    auto ubrania = make_shared<Place>();
    
    while (zz < 100) {
        mainMenuScreen();
        cin>>choosen;
        switch (choosen) {
            case plik:
                fileName = readFromFile(ubrania);
                break;
            case wyswietl:
                pokazStanMagazynu(ubrania);
                break;
            case usunElement:
                removeCloth(ubrania);
                break;
            case dodajElement:
                dodajUbranie(ubrania);
                break;
            case zapiszPlik:
                saveToFile(ubrania, fileName);
                break;
            case zamknij:
                zz = 100;
                break;
            default:
                break;
        }
        ++zz;
    }
    return 0;
}
