#include "Cure.hpp"

///////////////////////////////////////////////////////////////////////////////
// Constructors / Destructor
///////////////////////////////////////////////////////////////////////////////

Cure::Cure(): AMateria(CURE_TYPE)
{
    std::cout << "Cure Default constructor." << std::endl;
}

Cure::Cure(const std::string &type): AMateria(type)
{
    std::cout << "Cure constructor with type." << std::endl;
}

Cure::Cure(const Cure &ice)
{
    *this = ice;
    std::cout << "Cure Copy constructor." << std::endl;
}

Cure::~Cure()
{
    std::cout << "Cure destructor." << std::endl;
}

///////////////////////////////////////////////////////////////////////////////
// Operators
///////////////////////////////////////////////////////////////////////////////

Cure &Cure::operator=(const Cure &ice)
{
    type = ice.getType();

    std::cout << "Cure copy operator." << std::endl;

    return *this;
}

///////////////////////////////////////////////////////////////////////////////
// Member functions
///////////////////////////////////////////////////////////////////////////////

void Cure::use(ICharacter &target)
{
    std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}

AMateria *Cure::clone() const
{
    Cure *clone = new Cure();
    *clone = *this;
    return clone;
}
