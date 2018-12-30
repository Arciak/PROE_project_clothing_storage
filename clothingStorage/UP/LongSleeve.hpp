//
//  LongSleeve.hpp
//  clothingStorage
//
//  Created by Mac Artur on 28.12.2018.
//  Copyright © 2018 Mac Artur. All rights reserved.
//

#ifndef LongSleeve_hpp
#define LongSleeve_hpp

#include <stdio.h>
#include "Tshirt.hpp"
#include "cloth.hpp"

class LongSleeve : public Tshirt{
private:
    double sleeveLength_ = 0.0;
public:
    LongSleeve(const double& price, const string& size, const double& length, const double& width, const double& sleeveLength);
    
    double DlugoscRekawa() override;
};

#endif /* LongSleeve_hpp */
