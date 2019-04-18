//
//  LongSleeve.cpp
//  clothingStorage
//
//  Created by Mac Artur on 28.12.2018.
//  Copyright © 2018 Mac Artur. All rights reserved.
//

#include "LongSleeve.hpp"

LongSleeve::LongSleeve(const string& title, const double& price, const string& size, const double& length, const double& width, const double& sleeveLength) : Tshirt(title, price,size,length,width), sleeveLength_(sleeveLength){};


double LongSleeve::DlugoscRekawa(){
    return sleeveLength_;
}
