#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>

#include "ICharacter.hpp"
#include "AMateria.hpp"

#define MAX_MATERIAS 4

class Character : public ICharacter
{
protected:
    AMateria *materias[MAX_MATERIAS];
    unsigned int numberEquipedMaterias;
    std::string name;

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
    void use(int idx, Character &target);
};

#endif
