#ifndef WRONG_CAT_HPP
#define WRONG_CAT_HPP

#include <iostream>

#include "WrongAnimal.hpp"

class WrongCat: virtual public WrongAnimal
{

public:
    WrongCat();
    WrongCat(const WrongCat &cat);
    ~WrongCat();

    WrongCat &operator=(const WrongCat &cat);

    void makeSound(void) const;
};

#endif