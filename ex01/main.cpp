#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

static void showPolymorphicAnimal(Animal &animal)
{
    std::cout << "Animal type " << animal.getType() << " says: ";
    animal.makeSound();
    std::cout << std::endl;
}

static void showPolymorphicWrongAnimal(WrongAnimal &animal)
{
    std::cout << "Animal type " << animal.getType() << " says: ";
    animal.makeSound();
    std::cout << std::endl;
}

int main(void)
{
    Animal animal;
    showPolymorphicAnimal(animal);

    Dog dog;
    showPolymorphicAnimal(dog);

    Cat cat;
    showPolymorphicAnimal(cat);

    WrongAnimal wrongAnimal;
    showPolymorphicWrongAnimal(wrongAnimal);

    WrongCat wrongCat;
    showPolymorphicWrongAnimal(wrongCat);

    return 0;
}