#ifndef UTILS_H
#define UTILS_H

#include "pet.h"
#include <string>

std::string get_input(std::string msg = "");
int validate_input(std::string str, int min, int max);
bool validate_file_name(std::string& file_name);
bool file_exists(std::string& file_name);
int create_save_file(Pet& pet, std::string& file_name);

#endif
