#include "AMateria.hpp"

///////////////////////////////////////////////////////////////////////////////
// Constructors / Destructor
///////////////////////////////////////////////////////////////////////////////

AMateria::AMateria() : type(NULL)
{
    std::cout << "AMateria Default constructor." << std::endl;
}

AMateria::AMateria(const std::string &type) : type(type)
{
    std::cout << "AMateria constructor with type." << std::endl;
}

AMateria::AMateria(const AMateria &materia)
{
    *this = materia;
    std::cout << "AMateria Copy constructor." << std::endl;
}

AMateria::~AMateria()
{
    std::cout << "AMateria destructor." << std::endl;
}

///////////////////////////////////////////////////////////////////////////////
// Operators
///////////////////////////////////////////////////////////////////////////////

AMateria &AMateria::operator=(const AMateria &materia)
{
    type = materia.getType();

    std::cout << "AMateria copy operator." << std::endl;

    return *this;
}

///////////////////////////////////////////////////////////////////////////////
// Member functions
///////////////////////////////////////////////////////////////////////////////

const std::string &AMateria::getType() const
{
    return type;
}

void AMateria::use(ICharacter &target)
{
    std::cout << "AMateria used on target " << target.getName() << std::endl;
}