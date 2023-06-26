#ifndef PET_H
#define PET_H

#include <string>
#include <iostream>

constexpr std::pair<int,int> FULLNESS {0, 100};
constexpr std::pair<int,int> HAPPINESS {0, 10};

struct Pet
{
    std::string name {};
    std::string type {};
    int         happiness {2};  //Every pet starts with happiness of 2
    int         fullness {30};  //Every pet starts with fullness of 30
};

Pet create_new_pet(std::string name, std::string type);
void feed_pet(Pet& pet);

#endif
