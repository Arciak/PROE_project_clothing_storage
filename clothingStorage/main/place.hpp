//
//  place.hpp
//  clothingStorage
//
//  Created by Mac Artur on 18/11/2018.
//  Copyright © 2018 Mac Artur. All rights reserved.
//

#ifndef place_hpp
#define place_hpp

#include <iostream>
#include <string>
#include <iostream>
#include <fstream>
#include "cloth.hpp"
#include "storage.hpp"
using namespace std;

class Place {//Aplikacja, klasa komunikujaca sie z uzytkownikiem
private:
    //string clothType = "Na/Na";
    map<string,shared_ptr<Storage>> types_;
public:
    void creatTypeStorage(const shared_ptr<Storage>& type, string  clotheType);
    shared_ptr<Storage>& find(const string name);
    friend ostream& operator<<(ostream& out, const shared_ptr<Place>& place);
    void pokazTypyUbranWMagazynie(void);
    string pobierzNazwe(unsigned int element);
};

#endif /* place_hpp */
