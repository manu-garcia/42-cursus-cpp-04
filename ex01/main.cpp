#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#define NUMBER_ANIMALS 4

static void showPolymorphicAnimal(Animal &animal)
{
    std::cout << "Animal type " << animal.getType() << " says: ";
    animal.makeSound();
    std::cout << std::endl;
}

static Animal *animalFactory(int index)
{
    if (index < (NUMBER_ANIMALS / 2))
    {
        std::cout << "Creating a Dog #" << index << std::endl;
        return new Dog();
    }

    std::cout << "Creating a Cat #" << index << std::endl;
    return new Cat();
}

int main(void)
{
    Animal *animal[NUMBER_ANIMALS];

    for (int i = 0; i < NUMBER_ANIMALS; i++)
    {
        animal[i] = animalFactory(i);
        showPolymorphicAnimal(*animal[i]);
    }

    for (int i = 0; i < NUMBER_ANIMALS; i++)
    {
        std::cout << "Destroying Animal #" << i << std::endl;
        delete animal[i];
        animal[i] = nullptr;
        std::cout << std::endl;
    }

    std::cout << "Testing deep copy" << std::endl;

    Cat cat1;
    Cat cat2;

    cat1 = cat2;

    std::cout << std::endl << "Cleaning up..." << std::endl;

    return 0;
}