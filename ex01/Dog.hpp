#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>

#include "Animal.hpp"
#include "Brain.hpp"

class Dog: virtual public Animal
{
private:
    Brain *brain;

public:
    Dog();
    Dog(const Dog &dog);
    virtual ~Dog();

    Dog &operator=(const Dog &dog);

    virtual void makeSound(void) const;

};

#endif