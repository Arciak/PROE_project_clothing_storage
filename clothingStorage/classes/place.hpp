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
public:
    Place(void);
    Place(string fileName);
    ~Place(void){};
    Place& operator=(const Place& relocatePlace);
    void readFromFile(void);
    void saveToFile(void);
    void printOnScreen(void);
    void addElement(void);
    void removeCloth(void);
private:
    string fileName_;
    Storage supply_;
};

#endif /* place_hpp */
