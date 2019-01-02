//
//  Shirt.cpp
//  clothingStorage
//
//  Created by Mac Artur on 28.12.2018.
//  Copyright © 2018 Mac Artur. All rights reserved.
//

#include "Shirt.hpp"
Shirt::Shirt(const string& title, const double& price, const string& size, const double& length, const double& width, const double& sleeveLength,const double& collarCircuit) : LongSleeve(title, price, size, length, width, sleeveLength), collarCircuit_(collarCircuit){};

double Shirt::ObwodKolnierza(){
    return collarCircuit_;
}

