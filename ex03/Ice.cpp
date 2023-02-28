#include "Ice.hpp"

///////////////////////////////////////////////////////////////////////////////
// Constructors / Destructor
///////////////////////////////////////////////////////////////////////////////

Ice::Ice(): AMateria(ICE_TYPE)
{
    std::cout << "Ice Default constructor." << std::endl;
}

Ice::Ice(const std::string &type): AMateria(type)
{
    std::cout << "Ice constructor with type." << std::endl;
}

Ice::Ice(const Ice &ice)
{
    *this = ice;
    std::cout << "Ice Copy constructor." << std::endl;
}

Ice::~Ice()
{
    std::cout << "Ice destructor." << std::endl;
}

///////////////////////////////////////////////////////////////////////////////
// Operators
///////////////////////////////////////////////////////////////////////////////

Ice &Ice::operator=(const Ice &ice)
{
    type = ice.getType();

    std::cout << "Ice copy operator." << std::endl;

    return *this;
}

///////////////////////////////////////////////////////////////////////////////
// Member functions
///////////////////////////////////////////////////////////////////////////////

void Ice::use(ICharacter &target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

AMateria *Ice::clone() const
{
    Ice *clone = new Ice();
    *clone = *this;
    return clone;
}
