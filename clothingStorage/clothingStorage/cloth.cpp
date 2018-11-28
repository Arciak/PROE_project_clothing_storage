//
//  cloth.cpp
//  clothingStorage
//
//  Created by Mac Artur on 17/11/2018.
//  Copyright © 2018 Mac Artur. All rights reserved.
//

#include "cloth.hpp"

Cloth::Cloth(string clothType,string color, string size, unsigned int width, unsigned int length, unsigned int sleevesLength) : clothType_(clothType),color_(color) , size_(size), width_(width), length_(length), sleevesLength_(sleevesLength){
}

Cloth& Cloth::operator=(const Cloth &relocateCloth){
    clothType_ = relocateCloth.clothType_;
    color_ = relocateCloth.color_;
    size_ = relocateCloth.size_;
    width_ = relocateCloth.width_;
    length_ = relocateCloth.length_;
    sleevesLength_ = relocateCloth.sleevesLength_;
    return *this;
}

ostream& operator<<(ostream& out, const Cloth& thisCloth){
    if (thisCloth.clothType_ == "Spodnie")
        out<<thisCloth.clothType_<<"\t\t"<<thisCloth.color_<<"\t \t"<<thisCloth.size_<<" \t \t "<<thisCloth.width_<<"\t\t"<<"---"<<"\t\t\t"<<"---"<<"\t \t \t \t"<<thisCloth.length_;
    else if (thisCloth.clothType_ == "Koszulka")
         out<<thisCloth.clothType_<<"   \t"<<thisCloth.color_<<"\t \t"<<thisCloth.size_<<"\t\t "<<thisCloth.width_<<"\t"<<thisCloth.length_<<"\t\t\t"<<"---"<<"\t \t \t \t"<<"---";
    else if (thisCloth.clothType_=="Long-sleeve")
         out<<thisCloth.clothType_<<"  "<<thisCloth.color_<<"\t \t"<<thisCloth.size_<<" \t \t "<<thisCloth.width_<<"\t"<<thisCloth.length_<<"\t\t\t"<<thisCloth.sleevesLength_<<"\t \t \t \t"<<"---";
    else
        out<<"Nie rozpoznano ubrania! Upewnij się, że nasz sklep prowadzi taki produkt!";

    return out;
}
