//
//  wyjatki.h
//  clothingStorage
//
//  Created by Mac Artur on 14.01.2019.
//  Copyright © 2019 Mac Artur. All rights reserved.
//

#ifndef wyjatki_hpp
#define wyjatki_hpp

class file_exception : public std :: exception {
public :
    file_exception ( void ) : file_exception("blad przy otwieraniu pliku") {};
    file_exception(const std :: string& why) : why_(why) {};
    virtual const char* what(void) const noexcept {
        return why_. c_str ();
    }
private:
    std :: string why_;
};


class choosen_exception : public file_exception{
public:
    choosen_exception(void) : file_exception("Niedozwolony wybor") {};
    choosen_exception(const std :: string& why) : file_exception(why) {};
};

class writing_exception : public file_exception{
public:
    writing_exception(void) : file_exception("Blad w zapisie") {};
    writing_exception(const std :: string& why) : file_exception(why) {};
};
#endif /* wyjatki_h */
