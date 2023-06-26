#include "includes/pet.h"
#include "includes/utils.h"
#include <charconv>
#include <iostream>
#include <string>
#include <string_view>

void save_game(Pet& pet)
{
    while (true)
    {
        std::cout << "\nEnter the name for the save:\n";
        std::string file_name = get_input();
        if (!validate_file_name(file_name))
        {
            std::cout << "Name can only include letters and numbers!\n";
            continue;
        }
        else if (file_exists(file_name))
        {
            std::cout << "Save with this name already exists.\n";
            continue;
        }
        if (create_save_file(pet, file_name) == 0)
        {
            std::cout << "Game saved succesfully!\n\n";
            return ;
        }
        std::cout << "Something went wrong saving the file!\n";
    }
}

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
    std::cout << "2) Play with " << name << '\n';
    std::cout << "3) Put " << name << " to sleep\n";
    std::cout << "4) Display " << name << "'s stats\n";
    std::cout << "5) Save Game\n";
    std::cout << "6) Main Menu\n";
    std::cout << "7) Quit Game\n";
}

int game_loop(Pet& pet)
{
    while (true)
    {
        print_game_options(pet.name);
        int option = validate_input(get_input(), 1, 7);
        if (option == 1)
        {
            feed_pet(pet);
        }
        else if (option == 2)
        {
            play_with_pet(pet);
        }
        else if (option == 3)
        {
            put_to_sleep(pet);
        }
        else if (option == 4)
        {
            display_stats(pet);
        }
        else if (option == 5)
        {
            save_game(pet);
        }
        else if (option == 6)
        {
            return 1;
        }
        else if (option == 7)
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
