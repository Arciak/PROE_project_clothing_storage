//
//  storage.cpp
//  clothingStorage
//
//  Created by Mac Artur on 17/11/2018.
//  Copyright © 2018 Mac Artur. All rights reserved.
//

#include "storage.hpp"
#include "cloth.hpp"
using namespace std;

Storage::Storage(void) : sizeOfStorage_(2){
    clothes_ = new Cloth[2];
    numberOfClothes_ = 0;
}

Storage::Storage(unsigned int sizeOfStorag) : sizeOfStorage_(sizeOfStorag){
    clothes_ = new Cloth[sizeOfStorag];
}

Storage::~Storage(void){
    delete [] clothes_;
}

Storage& Storage::operator+ (const Cloth& addClothe){
    if (numberOfClothes_<sizeOfStorage_) {
        clothes_[numberOfClothes_] = addClothe;
        numberOfClothes_++;
    }
    else{
        Cloth* tempClothes = clothes_;//new
        sizeOfStorage_ = sizeOfStorage_+2;
        clothes_ = new Cloth [sizeOfStorage_];
        for (unsigned int ii = 0; ii<numberOfClothes_; ii++)
        clothes_ [ii] = tempClothes[ii];
        clothes_[numberOfClothes_] = addClothe;
        numberOfClothes_++;
        delete [] tempClothes;
    }
    return *this;
}


ostream& operator<<(ostream& out, const Storage& things){
    out<<"Lp:  "<<"Typ:     \t"<<"Kolor:  "<<"Rozmiar: "<<"Szerokosc: "<<"Dlugosc: "<<"Dlugosc rekawa: "<<"Dlugosc nogawki: "<<endl;
    for(unsigned int ii = 0; ii< things.numberOfClothes_; ii++){
        out<<ii+1<<"   "<<things.clothes_[ii]<<endl;
    }
    return out;
}

Storage& Storage::removeElement(unsigned int numberOfElementToRemove){
    for (unsigned int ii = numberOfElementToRemove; ii<(numberOfClothes_-1); ii++) {
        clothes_[ii] = clothes_[ii+1];
    }
    numberOfClothes_--;
    return *this;
}

int Storage::numberOfClothes(void){
    return  numberOfClothes_;
}
