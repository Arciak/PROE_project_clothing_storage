//
//  storage.cpp
//  clothingStorage
//
//  Created by Mac Artur on 17/11/2018.
//  Copyright © 2018 Mac Artur. All rights reserved.
//

#include "storage.hpp"

using namespace std;

void Storage::addCloth(const shared_ptr<Cloth>& ubranie){
    prices_.insert(make_pair(clothNumber_, ubranie));
    clothNumber_++;
}

void Storage::removeClothe(unsigned int id){
    prices_.erase(id);
}

