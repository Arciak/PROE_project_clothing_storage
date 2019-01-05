//
//  place.cpp
//  clothingStorage
//
//  Created by Mac Artur on 18/11/2018.
//  Copyright © 2018 Mac Artur. All rights reserved.
//

#include "place.hpp"

void Place::creatTypeStorage(const shared_ptr<Storage> &type, string clotheType){
    types_.insert(make_pair(clotheType, type));
}

shared_ptr<Storage>& Place::find(const string name){
    return types_.find(name)->second;
}

ostream& operator<<(ostream& out,const shared_ptr<Place>& place){
    for (auto itr = place->types_.begin(); itr != place->types_.end(); ++itr) {
        out << itr->first<<endl<<itr->second;
    }
    return out;
}

void Place::pokazTypyUbranWMagazynie(){
    unsigned int counter = 1;
    for (auto itr = types_.begin(); itr != types_.end(); ++itr) {
        cout <<counter<<"--> "<< itr->first<<endl;
        counter++;
    }
}

string Place::pobierzNazwe(unsigned int element){
    unsigned int counter = 1;
    string type = "Na/Na";
    for (auto itr = types_.begin(); itr != types_.end(); ++itr) {
        if (element == counter) {
            type = itr->first;
            break;
        }
        else counter++;
    }
    return type;
}
