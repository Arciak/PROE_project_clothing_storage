//
//  cloth.hpp
//  clothingStorage
//
//  Created by Mac Artur on 17/11/2018.
//  Copyright © 2018 Mac Artur. All rights reserved.
//

#ifndef cloth_hpp
#define cloth_hpp
#include <string>
#include <iostream>

using namespace std;

class Cloth {
public:
    virtual string Nazwa() = 0;
    virtual double Cena() = 0;
    virtual string Rozmiar() = 0;
    virtual double* DlugoscSzerokosc() = 0;
    virtual double DlugoscRekawa() = 0;
    virtual double ObwodKolnierza() = 0;
};

#endif /* cloth_hpp */
