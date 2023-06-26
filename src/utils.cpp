#include "../includes/utils.h"
#include "../includes/pet.h"
#include <charconv>
#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>

/*
**  Get's user input string. First prints message if it's provided, default is ""
*/
std::string get_input(std::string msg)
{
    if (msg != "")
        std::cout << msg;
    std::string input {};
    std::getline(std::cin >> std::ws, input);
    return input;
}

/*
**  Validates that input is integer and that it fits the asked range
*/
int validate_input(std::string str, int min, int max)
{
    int result {};
    auto [ptr, ec] = std::from_chars(str.data(), str.data() + str.size(), result);

    if ((ec == std::errc()) && (result >= min) && (result <= max))
        return result;
    std::cout << "That's not a valid option!\n";
    return 0;
}

/*
**  Checks the file name and returns true if it only includes alnum characters
*/
bool validate_file_name(std::string& file_name)
{
    for (auto c : file_name)
    {
        if (!isalnum(c))
            return false;
    }
    return true;
}

/*
**  Checks the saves folder for the file_name, returns true if it already exists
*/
bool file_exists(std::string& file_name)
{
    namespace fs = std::filesystem;
    fs::path dir = SAVE_PATH;
    if (!fs::exists(dir))
        return false;
    
    for (const auto& entry : fs::directory_iterator(dir))
    {
        if(entry.path() == SAVE_PATH + file_name)
            return true;
    }
    return false;
}

/*
**  Creates a new file and fills it with pet information. This works as a save
*/
int create_save_file(Pet& pet, std::string& file_name)
{
    std::ofstream file {SAVE_PATH + file_name};
    if (!file.is_open())
    {
        std::cout << "Couldn't open file!\n";
        return 1;
    }

    file
        << pet.name << ',' << pet.type << ',' << pet.happiness << ','
        << pet.fullness << ',' << pet.energy;

    file.close();
    return 0;
}

/*
**  Prints every save file, from which user selects the one he/she wants to load
*/
std::string select_save()
{
    namespace fs = std::filesystem;
    fs::path dir = SAVE_PATH;
    if (!fs::exists(dir))
        return "-false";
    
    int options { 1 };
    for (const auto& entry : fs::directory_iterator(dir))
    {
        std::cout << options++ << ") " << entry.path() << '\n';
    }
    int option = validate_input(get_input(), 1, options -1);
    if (option != 0)
    {
        options = 1;
        for (const auto& entry : fs::directory_iterator(dir))
        {
            if (option == options)
            {
                return entry.path();
            }
            options++;
        }
    }
    return "-false";
}
