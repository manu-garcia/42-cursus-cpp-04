#ifndef MATERIA_SOURCE_HPP
#define MATERIA_SOURCE_HPP

#include <iostream>

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

#define MAX_MATERIAS 4

class MateriaSource : public IMateriaSource
{
protected:
    AMateria *materias[MAX_MATERIAS];
    unsigned int numberLearntMaterias;

public:
    MateriaSource();
    MateriaSource(const MateriaSource &materiaSource);
    ~MateriaSource();

    MateriaSource &operator=(const MateriaSource &materiaSource);

    void freeMaterias();

    void learnMateria(AMateria *);
    AMateria *createMateria(std::string const &type);
};

#endif
