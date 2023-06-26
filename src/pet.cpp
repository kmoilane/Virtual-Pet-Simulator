#include "../includes/pet.h"
#include <iostream>
#include <string>

void feed_pet(Pet& pet)
{
    if (pet.fullness == FULLNESS.second)
        std::cout << pet.name << " is not hungry right now.\n";
    else if (pet.fullness < FULLNESS.second)
    {
        if (pet.fullness + 10 >= FULLNESS.second)
            pet.fullness = 100;
        else
            pet.fullness += 10;
        std::cout << pet.name << " is now fed and it's fullness is: "
            << pet.fullness << '\n';
        pet.happiness += 2;
        if (pet.happiness > 10)
            pet.happiness = 10;
        std::cout << pet.name << "'s happiness is now: " << pet.happiness << '\n';
    }
}

Pet create_new_pet(std::string name, std::string type)
{
    Pet new_pet {name, type};
    return new_pet;
}
