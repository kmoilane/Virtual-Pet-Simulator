#include "includes/pet.h"
#include "includes/utils.h"
#include <charconv>
#include <iostream>
#include <string>
#include <string_view>

void print_main_menu()
{
    std::cout << "Kamogotchi\n\n";
    std::cout << "1) Start With New Pet\n";
    std::cout << "2) Quit Game\n";
}

void print_game_options(std::string name)
{
    std::cout << "What do you want to do?\n\n";
    std::cout << "1) Feed " << name << '\n';
    std::cout << "2) Back to main menu\n";
    std::cout << "3) Quit Game\n";
}

int game_loop(Pet& pet)
{
    while (true)
    {
        print_game_options(pet.name);
        int option = validate_input(get_input(), 1, 3);
        if (option == 1)
        {
            feed_pet(pet);
        }
        else if (option == 2)
        {
            return 1;
        }
        else if (option == 3)
            return 0;
    }
}

int main_menu(Pet pet)
{
    while (true)
    {
        print_main_menu();
        int option = validate_input(get_input(), 1, 2);
        if (option == 1)
        {
            std::string name = get_input("Enter the name for the pet: ");
            std::string type = get_input("Enter the type for the pet: ");
            Pet new_pet { create_new_pet(name, type) };
            if (game_loop(new_pet) == 0)
                return 0;
        }
        else if (option == 2)
            return 0;
    }
}

int main(int argc, char* argv[])
{
    Pet active_pet {};
    while (true)
    {
        if (main_menu(active_pet) == 0)
            return 0;
    }
}