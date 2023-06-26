#include "../includes/utils.h"
#include "../includes/pet.h"
#include <charconv>
#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>

std::string get_input(std::string msg)
{
    if (msg != "")
        std::cout << msg;
    std::string input {};
    std::getline(std::cin >> std::ws, input);
    return input;
}

int validate_input(std::string str, int min, int max)
{
    int result {};
    auto [ptr, ec] = std::from_chars(str.data(), str.data() + str.size(), result);

    if ((ec == std::errc()) && (result >= min) && (result <= max))
        return result;
    std::cout << "That's not a valid option!\n";
    return 0;
}

bool validate_file_name(std::string& file_name)
{
    for (auto c : file_name)
    {
        if (!isalnum(c))
            return false;
    }
    return true;
}

bool file_exists(std::string& file_name)
{
    namespace fs = std::filesystem;
    fs::path dir = SAVE_PATH;
    if (!fs::exists(dir))
        return false;
    
    for (const auto& entry : fs::directory_iterator(dir))
    {
        if(entry.path() == file_name)
            return true;
    }
    return false;
}

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
