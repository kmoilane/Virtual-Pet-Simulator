#ifndef PET_H
#define PET_H

#include <string>
#include <iostream>

constexpr std::pair<int,int> FULLNESS {0, 100};
constexpr std::pair<int,int> HAPPINESS {0, 1000};
constexpr std::pair<int,int> ENERGY {0, 100};

struct Pet
{
    std::string name {};
    std::string type {};
    int         happiness {0};  //Every pet starts with happiness of 0
    int         fullness {30};  //Every pet starts with fullness of 30
    int         energy {50};    //Every pet starts with energy of 50
};

Pet create_new_pet(std::string name, std::string type);
void feed_pet(Pet& pet);
void play_with_pet(Pet& pet);
void put_to_sleep(Pet& pet);
void display_stats(Pet& pet);

#endif
