#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: virtual public Animal
{
private:
    Brain *brain;

public:
    Cat();
    Cat(const Cat &cat);
    virtual ~Cat();

    Cat &operator=(const Cat &cat);

    virtual void makeSound(void) const;
};

#endif