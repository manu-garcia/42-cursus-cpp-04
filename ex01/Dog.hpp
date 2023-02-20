#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>

#include "Animal.hpp"

class Dog: virtual public Animal
{

public:
    Dog();
    Dog(const Dog &dog);
    ~Dog();

    Dog &operator=(const Dog &dog);

    virtual void makeSound(void) const;

};

#endif