#include "Character.hpp"

///////////////////////////////////////////////////////////////////////////////
// Constructors / Destructor
///////////////////////////////////////////////////////////////////////////////

Character::Character() : name("Unknown"), numberEquipedMaterias(0)
{
    for (unsigned int i = 0; i < MAX_MATERIAS; i++)
    {
        materias[i] = NULL;
    }

    std::cout << "Character Default constructor." << std::endl;
}

Character::Character(const std::string name) : name(name), numberEquipedMaterias(0)
{
    for (unsigned int i = 0; i < MAX_MATERIAS; i++)
    {
        materias[i] = NULL;
    }

    std::cout << "Character constructor with name." << std::endl;
}

Character::Character(const Character &character)
{
    *this = character;
    std::cout << "Character Copy constructor." << std::endl;
}

Character::~Character()
{
    freeMaterias();
    std::cout << "Character destructor." << std::endl;
}

///////////////////////////////////////////////////////////////////////////////
// Operators
///////////////////////////////////////////////////////////////////////////////

Character &Character::operator=(const Character &character)
{
    name = character.getName();
    // We free them!! But unequiping we do not! Issue here?
    freeMaterias();
    numberEquipedMaterias = character.numberEquipedMaterias;

    for (unsigned int i = 0; i < MAX_MATERIAS; i++)
    {
        // We free them!! But unequiping we do not! Issue here?
        *materias[i] = *character.materias[i];
    }
    std::cout << "Character copy operator." << std::endl;

    return *this;
}

///////////////////////////////////////////////////////////////////////////////
// Member functions
///////////////////////////////////////////////////////////////////////////////
void Character::freeMaterias()
{
    numberEquipedMaterias = 0;
    for (unsigned int i = 0; i < MAX_MATERIAS; i++)
    {
        if (materias[i] != NULL)
        {
            delete materias[i];
            materias[i] = NULL;
        }
    }
}

std::string const &Character::getName() const
{
    return name;
}

void Character::equip(AMateria *m)
{
    if (!m)
    {
        std::cout << "Equiping invalid materia." << std::endl;
        return;
    }

    if (numberEquipedMaterias > MAX_MATERIAS)
    {
        std::cout << "Too many equiped materias." << std::endl;
        return;
    }

    for (unsigned int i = 0; i < MAX_MATERIAS; i++)
    {
        if (materias[i] == NULL)
        {
            // Subject says it must not delete the materia. So we cannot duplicate it here.
            materias[i] = m;
            numberEquipedMaterias++;
            return;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx > (MAX_MATERIAS - 1))
    {
        std::cout << "Unequiping invalid materia index. Index higher than max allowed." << std::endl;
        return;
    }

    if (materias[idx] == NULL)
    {
        std::cout << "Unequiping invalid materia. It was not equiped." << std::endl;
        return;
    }

    // Subject says it must not delete the materia. Leaks!!?
    // delete materias[idx];
    materias[idx] = NULL;
    numberEquipedMaterias--;
}

void Character::use(int idx, ICharacter &target)
{
    if (idx > (MAX_MATERIAS - 1))
    {
        std::cout << "Using invalid materia index. Index higher than max allowed." << std::endl;
        return;
    }

    if (materias[idx] == NULL)
    {
        std::cout << "Using invalid materia. It was not equiped." << std::endl;
        return;
    }

    std::cout << getName() << " using materia " << materias[idx]->getType() << " on target " << target.getName() << std::endl;
}