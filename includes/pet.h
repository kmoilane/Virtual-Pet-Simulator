#ifndef PET_H
#define PET_H

#include <string>
#include <iostream>


inline constexpr static std::pair<int,int>    FULLNESS {0, 100};
inline constexpr static std::pair<int,int>    HAPPINESS {0, 1000};
inline constexpr static std::pair<int,int>    ENERGY {0, 100};


struct Pet
{
    constexpr static int init_energy = 50;
    constexpr static int init_happiness = 0;
    constexpr static int init_fullness = 50;
    std::string name {""};
    std::string type {""};
    int         happiness {init_happiness};  //Every pet starts with happiness of 0
    int         fullness {init_fullness};  //Every pet starts with fullness of 30
    int         energy {init_energy};    //Every pet starts with energy of 50
};

Pet create_new_pet(std::string name, std::string type);
void feed_pet(Pet& pet);
void play_with_pet(Pet& pet);
void put_to_sleep(Pet& pet);
void display_stats(Pet& pet);

#endif
