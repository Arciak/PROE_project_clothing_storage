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
using namespace std;

class Storage { //Kolekcja, klasa tworzaca tablice z clasy clothe w celu storzenia kolekcji
public:
    Storage(void);
    Storage(unsigned int sizeOfStorag);
    ~Storage(void);
    Cloth& operator[](unsigned int ii){return clothes_[ii];}
    friend ostream& operator<<(ostream& out, const Storage& thigs);
    Storage& operator+ (const Cloth& addClothe);
    Storage& removeElement(unsigned int numberOfElementToRemove);
    int numberOfClothes(void);
    
private:
    Cloth* clothes_;
    unsigned int numberOfClothes_ = 0;
    unsigned int sizeOfStorage_ = 2;
};

#endif /* storage_hpp */
