#ifndef PET_H
#define PET_H

#include <string>

struct Pet
{
    std::string name {};
    std::string type {};
};

Pet create_new_pet(std::string name, std::string type);

#endif
