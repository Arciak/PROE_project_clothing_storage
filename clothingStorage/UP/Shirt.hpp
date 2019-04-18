//
//  Shirt.hpp
//  clothingStorage
//
//  Created by Mac Artur on 28.12.2018.
//  Copyright © 2018 Mac Artur. All rights reserved.
//

#ifndef Shirt_hpp
#define Shirt_hpp

#include <stdio.h>
#include "Tshirt.hpp"
#include "LongSleeve.hpp"

class Shirt: public LongSleeve{
private:
    double collarCircuit_ = 0.0;
public:
    Shirt(const string& title, const double& price, const string& size, const double& length, const double& width, const double& sleeveLength,const double& collarCircuit);
    double ObwodKolnierza() override;
};

#endif /* Shirt_hpp */
