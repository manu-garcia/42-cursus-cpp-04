#include "WrongAnimal.hpp"

#define WRONG_ANIMAL_TYPE "WrongAnimal"

///////////////////////////////////////////////////////////////////////////////
// Constructors / Destructor
///////////////////////////////////////////////////////////////////////////////

WrongAnimal::WrongAnimal() : type(WRONG_ANIMAL_TYPE)
{
    std::cout << "WrongAnimal Default constructor." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &animal)
{
    *this = animal;
    std::cout << "WrongAnimal Copy constructor." << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor." << std::endl;
}

///////////////////////////////////////////////////////////////////////////////
// Operators
///////////////////////////////////////////////////////////////////////////////

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &animal)
{
    type = animal.getType();

    std::cout << "WrongAnimal copy operator." << std::endl;

    return *this;
}

///////////////////////////////////////////////////////////////////////////////
// Member functions
///////////////////////////////////////////////////////////////////////////////

std::string WrongAnimal::getType(void) const
{
    return type;
}

void WrongAnimal::makeSound(void) const
{
    std::cout << "generic wrong animal sound" << std::endl;
}
