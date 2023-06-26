#include "../includes/utils.h"
#include "../includes/pet.h"
#include <charconv>
#include <iostream>
#include <string>

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
