#ifndef WRONG_ANIMAL_HPP
#define WRONG_ANIMAL_HPP

#include <iostream>

class WrongAnimal
{
protected:
    std::string type;

public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal &animal);
    ~WrongAnimal();

    WrongAnimal &operator=(const WrongAnimal &animal);

    std::string getType(void) const;
    void makeSound(void) const;

};

#endif