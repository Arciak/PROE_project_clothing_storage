//
//  storage.hpp
//  clothingStorage
//
//  Created by Mac Artur on 17/11/2018.
//  Copyright © 2018 Mac Artur. All rights reserved.
//

#ifndef storage_hpp
#define storage_hpp
#include "cloth.hpp"
#include <iostream>
#include <map>
using namespace std;


class Storage {
private:
    unsigned int clothNumber_ = 0;
    shared_ptr<Cloth> ubranie_;
    map<unsigned int , shared_ptr<Cloth>> prices_;
    
public:
    void addCloth(const shared_ptr<Cloth>& ubranie);
    void removeClothe(unsigned int id);
};

#endif /* storage_hpp */
