#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>

#include "ICharacter.hpp"
#include "AMateria.hpp"

#define MAX_MATERIAS 4

class Character : public ICharacter
{
protected:
    std::string name;
    unsigned int numberEquipedMaterias;
    AMateria *materias[MAX_MATERIAS];

public:
    Character();
    Character(const std::string name);
    Character(const Character &character);
    ~Character();

    Character &operator=(const Character &character);

    void freeMaterias();

    std::string const &getName() const;
    void equip(AMateria *m);
    void unequip(int idx);
    void use(int idx, ICharacter &target);
};

#endif
