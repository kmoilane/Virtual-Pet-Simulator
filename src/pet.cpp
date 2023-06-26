#include "../includes/pet.h"
#include "../includes/utils.h"
#include <iostream>
#include <string>

void change_energy(Pet& pet, int amount)
{
    pet.energy += amount;
    if (pet.energy > ENERGY.second)
        pet.energy = ENERGY.second;
    else if (pet.energy < ENERGY.first)
        pet.energy = ENERGY.first;
}

void increase_happiness(Pet& pet, int amount)
{
    pet.happiness += amount;
    if (pet.happiness > HAPPINESS.second)
        pet.happiness = HAPPINESS.second;
}

void display_stats(Pet& pet)
{
    std::cout << '\n' << pet.name << "'s stats:\n\n";
    std::cout << "Happiness: " << pet.happiness << '/' << HAPPINESS.second
        << '\n';
    std::cout << "Fullness: " << pet.fullness << '/' << FULLNESS.second << '\n';
    std::cout << "Energy: " << pet.energy << '/' << ENERGY.second << '\n';
}

void put_to_sleep(Pet& pet)
{
    if (pet.energy == ENERGY.second)
        std::cout << pet.name << " is not tired at all!\n";
    else
    {
        change_energy(pet, 25);
        std::cout << pet.name << " sleeps like a baby.\nIt's energy is now: "
        << pet.energy << '\n';
    }
}

void play_with_pet(Pet& pet)
{
    if (pet.energy - 10 < 0)
        std::cout << pet.name << " is too tired to play right now.\n";
    else
    {
        increase_happiness(pet, 5);
        change_energy(pet, -10);
        std::cout << "You play with " << pet.name
            << "\nIt's happiness is now: " << pet.happiness << '\n';
        std::cout << pet.name << "'s energy is now: " << pet.energy << '\n';
    }
}

void feed_pet(Pet& pet)
{
    if (pet.fullness == FULLNESS.second)
        std::cout << pet.name << " is not hungry right now.\n";
    else
    {
        if (pet.fullness + 10 >= FULLNESS.second)
            pet.fullness = 100;
        else
            pet.fullness += 10;
        std::cout << pet.name << " is now fed and it's fullness is: "
            << pet.fullness << '\n';
        increase_happiness(pet, 2);
        std::cout << pet.name << "'s happiness is now: " << pet.happiness << '\n';
    }
}

Pet create_new_pet(std::string name, std::string type)
{
    Pet new_pet {name, type};
    return new_pet;
}
