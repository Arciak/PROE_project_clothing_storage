//
//  Tshirt.hpp
//  clothingStorage
//
//  Created by Mac Artur on 28.12.2018.
//  Copyright © 2018 Mac Artur. All rights reserved.
//

#ifndef Tshirt_hpp
#define Tshirt_hpp

#include <stdio.h>
#include "cloth.hpp"

class Tshirt : public Cloth{
private:
    string title_ = "Na/Na";
    double price_ = 0.0;
    string size_ = "Na/Na";
    double length_ = 0.0;
    double width_ = 0.0;
    double* wymiary_;
public:
    Tshirt(const string& title, const double& price, const string& size, const double& length, const double& width);
    ~Tshirt(void);
    string Nazwa();
    double Cena();
    string Rozmiar();
    double* DlugoscSzerokosc();
    double DlugoscRekawa();
    double ObwodKolnierza();
    
    friend ostream& operator<<(ostream& out, const Tshirt& thisTshirt);
};


#endif /* Tshirt_hpp */
