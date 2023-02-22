#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

#define NUMBER_BRAIN_IDEAS 100

class Brain
{
protected:
    std::string ideas[NUMBER_BRAIN_IDEAS];

public:
    Brain();
    Brain(const Brain &brain);
    ~Brain();

    Brain &operator=(const Brain &brain);

    unsigned int getNumberIdeas(void) const;
};

#endif