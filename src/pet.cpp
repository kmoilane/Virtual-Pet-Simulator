#include "../includes/pet.h"
#include <iostream>
#include <string>

Pet create_new_pet(std::string name, std::string type)
{
    Pet new_pet {name, type};
    return new_pet;
}
