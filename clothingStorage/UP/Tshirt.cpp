//
//  Tshirt.cpp
//  clothingStorage
//
//  Created by Mac Artur on 28.12.2018.
//  Copyright © 2018 Mac Artur. All rights reserved.
//

#include "Tshirt.hpp"

Tshirt::Tshirt(const double& price, const string& size, const double& length, const double& width) : price_(price), size_(size), length_(length), width_(width){
    wymiary_ = new double [2];
    wymiary_[0] = length_;
    wymiary_[1] = width_;
}

Tshirt::~Tshirt(){
    delete [] wymiary_;
}

double Tshirt:: Cena(){
    return price_;
}

string Tshirt::Rozmiar(){
    return size_;
}

double* Tshirt::DlugoscSzerokosc(){
    return wymiary_;
}

double Tshirt::DlugoscRekawa(){
    return 0.0;
}

double Tshirt::ObwodKolnierza(){
    return 0.0;
}
