#include "MateriaSource.hpp"

///////////////////////////////////////////////////////////////////////////////
// Constructors / Destructor
///////////////////////////////////////////////////////////////////////////////

MateriaSource::MateriaSource() : numberLearntMaterias(0)
{
    for (unsigned int i = 0; i < MAX_MATERIAS; i++)
    {
        materias[i] = NULL;
    }

    std::cout << "MateriaSource Default constructor." << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &materiaSource)
{
    *this = materiaSource;
    std::cout << "MateriaSource Copy constructor." << std::endl;
}

MateriaSource::~MateriaSource()
{
    freeMaterias();
    std::cout << "MateriaSource destructor." << std::endl;
}

///////////////////////////////////////////////////////////////////////////////
// Operators
///////////////////////////////////////////////////////////////////////////////

MateriaSource &MateriaSource::operator=(const MateriaSource &materiaSource)
{
    // We free them!! But unequiping we do not! Issue here?
    freeMaterias();
    numberLearntMaterias = materiaSource.numberLearntMaterias;
    for (unsigned int i = 0; i < MAX_MATERIAS; i++)
    {
        // We free them!! But unequiping we do not! Issue here?
        // clone here?
        *materias[i] = *materiaSource.materias[i];
    }
    std::cout << "MateriaSource copy operator." << std::endl;

    return *this;
}

///////////////////////////////////////////////////////////////////////////////
// Member functions
///////////////////////////////////////////////////////////////////////////////
void MateriaSource::freeMaterias()
{
    numberLearntMaterias = 0;
    for (unsigned int i = 0; i < MAX_MATERIAS; i++)
    {
        if (materias[i] != NULL)
        {
            delete materias[i];
            materias[i] = NULL;
        }
    }
}

void MateriaSource::learnMateria(AMateria *m)
{
    if (!m)
    {
        std::cout << "Learning invalid materia." << std::endl;
        return;
    }

    if (numberLearntMaterias > MAX_MATERIAS)
    {
        std::cout << "Too many learnt materias." << std::endl;
        return;
    }

    for (unsigned int i = 0; i < MAX_MATERIAS; i++)
    {
        if (materias[i] == NULL)
        {
            // Subject says it must not delete the materia. So we cannot duplicate it here.
            materias[i] = m->clone();
            numberLearntMaterias++;
            return;
        }
    }
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
    for (unsigned int i = 0; i < MAX_MATERIAS; i++)
    {
        if (materias[i] != NULL && materias[i]->getType() == type)
        {
            return materias[i]->clone();
        }
    }

    return 0;
}