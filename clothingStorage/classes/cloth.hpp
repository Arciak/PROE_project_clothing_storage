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


class Cloth { //Element, klasa reprezentujaca ubranie w sklepie
public:
    Cloth(void){};
    Cloth(string clothType,string color, string size, unsigned int width_,unsigned int lenght,  unsigned int sleevesLength);
    friend ostream& operator<<(ostream& out, const Cloth& thisCloth);
    Cloth& operator=(const Cloth& relocateCloth);
    string clotheType(void) const {return clothType_;}
    string size(void) const {return size_;}
private:
    string clothType_;
    string color_;
    string size_;
    unsigned int width_;
    unsigned int length_;
    unsigned int sleevesLength_;
    
};

#endif /* cloth_hpp */
