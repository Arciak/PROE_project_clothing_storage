//
//  place.cpp
//  clothingStorage
//
//  Created by Mac Artur on 18/11/2018.
//  Copyright © 2018 Mac Artur. All rights reserved.
//

#include "place.hpp"

Place::Place(const char *fileName) : fileName_(fileName){
}

void Place::readFromFile(void){
    string word;
    int counter = 0; int stringCounter = 0; int intCounter = 0; int tempInt;
    string* stringsToStorage_ = new string[3];
    int* intsToStorage_ = new int[3];
    fstream file;
    file.open(fileName_);
    file.ignore ( std::numeric_limits<std::streamsize>::max(), '\n' );
    while (file >> word){
        if(counter>=1 && counter<=3){
            stringsToStorage_[stringCounter++] = word;
            counter++;
        }
        else if (counter>=4&&counter<=7){
            tempInt = atoi(word.c_str()); //stoi funkcja z C++
            if (tempInt!=0)
                intsToStorage_[intCounter++] = atoi(word.c_str());
            counter++;
        }
        else if (counter == 0){
            counter++;}
        else if (counter == 8){
            supply_+ Cloth(stringsToStorage_[0],stringsToStorage_[1],stringsToStorage_[2],intsToStorage_[0],intsToStorage_[1],intsToStorage_[2]);
            counter = 1; stringCounter = 0; intCounter = 0;
            delete [] stringsToStorage_;
            delete [] intsToStorage_;
            stringsToStorage_ = new string[3];
            intsToStorage_ = new int[3];
        }
    }
    supply_+Cloth(stringsToStorage_[0],stringsToStorage_[1],stringsToStorage_[2],intsToStorage_[0],intsToStorage_[1],intsToStorage_[2]);
    cout<<"Odczytano plik: "<< fileName_<<endl;
    file.close();
}

void Place::saveToFile(void){
    ofstream file;
    file.open (fileName_);
    file << supply_;
    cout<<"Odbył się zapis do pliku: "<<fileName_ <<endl;
    file.close();
}

void Place::printOnScreen(void){
    cout<<supply_;
}

void Place::addElement(void){
    string* stringsToStorage_ = new string[3];
    int* intsToStorage_ = new int[3];
    cout<<"Wprowadz typ:  Koszulka, Spodnie, Long-sleeve"<<endl;
    cin>>stringsToStorage_[0];
    cout<<"Kolor (string): ";
    cin>>stringsToStorage_[1];
    cout<<"Rozmiar (string): ";
    cin>>stringsToStorage_[2];
    cout<<"Szerokość (int): ";
    cin>>intsToStorage_[0];
    cout<<"Dlugosc/Dlugosc nogawki: ";
    cin>>intsToStorage_[1];
    cout<<"Dlugosc rekawa: ";
    cin>>intsToStorage_[2];
    cout<<endl;
    supply_+Cloth(stringsToStorage_[0], stringsToStorage_[1], stringsToStorage_[2], intsToStorage_[0], intsToStorage_[1], intsToStorage_[2]);
    delete [] stringsToStorage_;
    delete [] intsToStorage_;
}

void Place::removeCloth(void){
    int element;
    cout<<"Liczba ubran na stanie = "<<supply_.numberOfClothes()<<endl;
    cout<<"Element do usuniecia (int): ";
    cin>>element;
    supply_.removeElement(element-1);
}
