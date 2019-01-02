//
//  storage.cpp
//  clothingStorage
//
//  Created by Mac Artur on 17/11/2018.
//  Copyright © 2018 Mac Artur. All rights reserved.
//

#include "storage.hpp"

using namespace std;

void Storage::addCloth(const shared_ptr<Cloth>& ubranie){
    clothes_.insert(make_pair(clothNumber_, ubranie));
    clothNumber_++;
    cout <<endl;
}

void Storage::removeClothe(unsigned int id){
    clothes_.erase(id);
}

ostream& operator<<(ostream& out,const shared_ptr<Storage>& myStorage){
    for (auto itr = myStorage->clothes_.begin(); itr != myStorage->clothes_.end(); ++itr) {
         out << itr->first<<"\t"<<itr->second->Nazwa() <<"\t"<<itr->second->Cena()<<"\t"<<itr->second->Rozmiar()<<"\t"<<itr->second->DlugoscSzerokosc()[0]<<"\t"<<itr->second->DlugoscSzerokosc()[1]<<"\t"<<itr->second->DlugoscRekawa()<<"\t"<<itr->second->ObwodKolnierza()<<endl;
    }
    return out;
}
