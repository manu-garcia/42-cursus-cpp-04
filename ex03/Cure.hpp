#ifndef CURE_HPP
#define CURE_HPP

#include <iostream>

#include "AMateria.hpp"
#include "ICharacter.hpp"

#define CURE_TYPE "cure"

class Cure : public AMateria
{
public:
    Cure();
    Cure(const Cure &cure);
    Cure(std::string const &type);
    virtual ~Cure();

    Cure &operator=(const Cure &cure);

    AMateria *clone() const;
    void use(ICharacter &target);
};

#endif