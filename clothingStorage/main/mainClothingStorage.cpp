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
    string fileName;
    int zz = 0 ;
    int choosen = 0;
    
    welcomeScreen();
 
    char * fileName_ = new char [fileName.length()+1];
    strcpy (fileName_, fileName.c_str());
  
    auto ceny = make_shared<Storage>();
    
    while (zz < 100) {
        menuScreen(fileName);
        cin>>choosen;
        switch (choosen) {
            case plik:
               
                break;
            case wyswietl:
                //ourStorage.printOnScreen();
                break;
            case usunElement:
                //ourStorage.removeCloth();
                break;
            case dodajElement:
                dodajUbranie(ceny);
                break;
            case zapiszPlik:
                //ourStorage.saveToFile();
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
