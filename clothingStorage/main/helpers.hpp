//
//  helpers.hpp
//  clothingStorage
//
//  Created by Mac Artur on 29.12.2018.
//  Copyright © 2018 Mac Artur. All rights reserved.
//

#ifndef helpers_hpp
#define helpers_hpp

#include <stdio.h>
#include "storage.hpp"
#include "place.hpp"
#include "Shirt.hpp"
#include <vector>

void welcomeScreen(void){
    cout<<"-------------------------------------------------------------------------------------"<<endl;
    cout<<"Witamy w magazynie ubran :) "<<endl;
    cout<<"Ponizej znajduje sie manu naszej aplikacji prosimy o wybranie jednej z opcji."<<endl;
    cout<<"-------------------------------------------------------------------------------------"<<endl<<endl;
}

void mainMenuScreen(void){
    cout<<endl<<"---------- W celu dokonia zmian wybierz jedna z ponizszych opcji: ---------------"<<endl;
    cout<<"1 --> wczytaj plik"<<endl;
    cout<<"2 --> wyswietl elementy na ekranie"<<endl;
    cout<<"3 --> usun element"<<endl;
    cout<<"4 --> dodaj element"<<endl;
    cout<<"5 --> zapisz zmiany do pliku"<<endl;
    cout<<"9 --> zamknij system"<<endl<<endl;
}

void dodajUbranie(shared_ptr<Place>& sklad){
    string nazwa = "Na/Na";
    double cena = 0.0;
    string rozmiar = "Na/Na";
    double dlugosc = 0.0;
    double szerokosc = 0.0;
    double dlugoscRekawa = 0.0;
    double obwodKolnierza = 0.0;
    
     unsigned int tempChoose = 0;
    
    cout<<"Wybierz rodzaj ubrania do dodania"<<endl;
    cout<<"1--> Koszulka"<<endl;
    cout<<"2--> Long-Sleeve"<<endl;
    cout<<"3--> Koszula"<<endl;
    cin>>tempChoose;
        cout<<"Podaj nazwe ubrania: ";
        cin>>nazwa;
        cout<<"Podaj cene (double): ";
        cin>>cena;
        cout<<"Podaj rozmiar (string): ";
        cin>>rozmiar;
        cout<<"Podaj dlugosc (double): ";
        cin>>dlugosc;
        cout<<"Podaj szerokosc (double): ";
        cin>>szerokosc;
    if (tempChoose == 1) {
        auto ciuszek = make_shared<Tshirt>(nazwa, cena, rozmiar, dlugosc, szerokosc);
        sklad->creatTypeStorage(make_shared<Storage>(), "Koszulka");
        auto zbior = sklad->find("Koszulka");
        zbior->addCloth(ciuszek);
    }
    else if(tempChoose == 2){
        cout<<"Podaj dlugosc rekawa (double): ";
        cin>>dlugoscRekawa;
        auto ciuszek = make_shared<LongSleeve>(nazwa, cena, rozmiar, dlugosc, szerokosc, dlugoscRekawa);
        sklad->creatTypeStorage(make_shared<Storage>(), "Long-Sleeve");
        auto zbior = sklad->find("Long-Sleeve");
        zbior->addCloth(ciuszek);
    }
    else if (tempChoose == 3){
        cout<<"Podaj dlugosc rekawa (double): ";
        cin>>dlugoscRekawa;
        cout<<"Podaj obwod kolnierza (double): ";
        cin>>obwodKolnierza;
        auto ciuszek = make_shared<Shirt>(nazwa, cena, rozmiar, dlugosc, szerokosc, dlugoscRekawa, obwodKolnierza);
        sklad->creatTypeStorage(make_shared<Storage>(), "Koszula");
        auto zbior = sklad->find("Koszula");
        zbior->addCloth(ciuszek);
    }
}

void pokazStanMagazynu(shared_ptr<Place>& sklad){
    cout<<"Obecnie na stanie mamy: "<<endl;
    cout<<sklad;
}

void saveToExternalFile(shared_ptr<Place>& sklad){
    string fileName;
    cout<<"Podaj nazwę pliku z rozszerzeniem"<<endl;
    cin>>fileName;
    ofstream file;
    char * fileName_ = new char [fileName.length()+1];
    strcpy (fileName_, fileName.c_str());
    file.open (fileName);
    file << sklad;
    cout<<"Odbył się zapis do pliku: "<<fileName<<endl;
    file.close();
    delete [] fileName_;
}

void saveToCurrentFile(shared_ptr<Place>& sklad, string currentFileName){
    ofstream file;
    char * fileName_ = new char [currentFileName.length()+1];
    strcpy (fileName_, currentFileName.c_str());
    file.open (currentFileName);
    file << sklad;
    cout<<"Odbył się zapis do pliku: "<<currentFileName<<endl;
    file.close();
    delete [] fileName_;
}


void saveToFile(shared_ptr<Place>& sklad, string currentFileName){
    unsigned int choosen;
    cout<<"1 --> nadpisz dane z pliku wczytanego: "<<currentFileName<<endl;
    cout<<"2 --> zapisz dane do inne pliku"<<endl;
    cin>>choosen;
    switch (choosen) {
        case 1:
            saveToCurrentFile(sklad, currentFileName);
            break;
        case 2:
            saveToExternalFile(sklad);
            break;
        default:
            break;
    }
}

void removeCloth(shared_ptr<Place>& sklad){
    unsigned int choosen = 0;
    string type = "Na/Na";
    cout<<"Wybierz rodzaj ubrania do usuniecia: "<<endl;
    sklad->pokazTypyUbranWMagazynie();
    cin>>choosen;
    type = sklad->pobierzNazwe(choosen);
    auto storage = sklad->find(type);
    cout<<"Wybierz element do usuniecia: "<<endl;
    cout<<storage;
    cin>>choosen;
    storage->removeClothe(choosen);
}

string readFromFile(shared_ptr<Place>& sklad){
    string fileName_; string word; string line; string delimiter = "\t"; string token;
    vector<string> divideLine;
    size_t pos = 0;
    cout<<"Podaj nazwę pliku: ";
    cin>>fileName_;
    char * fileName= new char [fileName_.length()+1];
    strcpy (fileName, fileName_.c_str());
    fstream file;
    file.open(fileName);
    //file.ignore ( numeric_limits<streamsize>::max(), '\n' );
    while (!file.eof()){
        line.clear();
        divideLine.clear();
        getline(file,line);
        if(line.size()<12){
            word = line;
            sklad->creatTypeStorage(make_shared<Storage>(), word);
        }
        else if (line.size()>=12){
            while ((pos = line.find(delimiter)) != string::npos) {
                token = line.substr(0, pos);
                divideLine.push_back(token);
                line.erase(0, pos + delimiter.length());
            }
            token = line.substr(0, pos);
            divideLine.push_back(token);
            if(word=="Koszulka"){
                auto ciuszek = make_shared<Tshirt>(divideLine[1], atoi(divideLine[2].c_str()), divideLine[3], atoi(divideLine[4].c_str()), atoi(divideLine[5].c_str()));
                auto zbior = sklad->find(word);
                zbior->addCloth(ciuszek);}
            else if (word == "Long-Sleeve"){
                auto ciuszek = make_shared<LongSleeve>(divideLine[1], atoi(divideLine[2].c_str()), divideLine[3], atoi(divideLine[4].c_str()), atoi(divideLine[5].c_str()), atoi(divideLine[6].c_str()));
                auto zbior = sklad->find(word);
                zbior->addCloth(ciuszek);}
            else if (word == "Koszula"){
                auto ciuszek = make_shared<Shirt>(divideLine[1], atoi(divideLine[2].c_str()), divideLine[3], atoi(divideLine[4].c_str()), atoi(divideLine[5].c_str()), atoi(divideLine[6].c_str()), atoi(divideLine[7].c_str()));
                auto zbior = sklad->find(word);
                zbior->addCloth(ciuszek);}
            }
    }

    return fileName_;
}

enum operacja {
    plik = 1,
    wyswietl = 2,
    usunElement = 3,
    dodajElement = 4,
    zapiszPlik = 5,
    zamknij = 9
};


#endif /* helpers_hpp */
