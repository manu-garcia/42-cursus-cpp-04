#ifndef ICE_HPP
#define ICE_HPP

#include <iostream>

#include "AMateria.hpp"
#include "ICharacter.hpp"

#define ICE_TYPE "ice"

class Ice : public AMateria
{
public:
    Ice();
    Ice(const Ice &ice);
    Ice(std::string const &type);
    virtual ~Ice();

    Ice &operator=(const Ice &ice);

    AMateria *clone() const;
    void use(ICharacter &target);
};

#endif