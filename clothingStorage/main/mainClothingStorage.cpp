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
    bool valid = false;
    
    string fileName = "temp.txt";
    welcomeScreen();
  
    auto ubrania = make_shared<Place>();
    
    while (!valid) {
        mainMenuScreen();
        cin>>choosen;
        switch (choosen) {
            case plik:
                try{
                    fileName = readFromFile(ubrania);
                }
                catch(const file_exception& ee){
                    cout<<ee.what()<<"  -----> Sproboj wczytac inny plik"<<endl;
                }
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
                try{
                saveToFile(ubrania, fileName);
                }
                catch(const file_exception& ee){
                    cout<<ee.what()<<endl;
                }
                break;
            case zamknij:
                valid = true;
                break;
            default:
                break;
        }
        ++zz;
    }
    return 0;
}
