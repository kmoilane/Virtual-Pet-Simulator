#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "includes/doctest.h"
#include "../includes/pet.h"
#include "../includes/utils.h"

TEST_CASE("TESTING INPUT VALIDATIONS WITH RANGE")
{
    SUBCASE("Expecting int, getting string")
    {
        CHECK(validate_input("testi", 1, 2) == 0);
        CHECK(validate_input("testi", 0, 2) == 0);
    }
    SUBCASE("Expecting int, getting int")
    {
        CHECK(validate_input("5", 1, 2) == 0);
        CHECK(validate_input("5", 1, 5) == 5);
    }
    SUBCASE("Expecting int, getting float")
    {
        CHECK(validate_input("5.6", 1, 2) == 0);
        CHECK(validate_input("5.6", 1, 5) == 5);
    }
}

TEST_CASE("TESTING FILE NAME VALIDATIONS")
{
    std::string str = "testifilu-3";
    std::string str2 = "musto 1";
    SUBCASE("Name includes invalid characters")
    {
        CHECK(validate_file_name(str) == 0);
        CHECK(validate_file_name(str2) == 0);
    }

    str = "testi123testi";
    str2 = "01234567898";
    SUBCASE("File name is valid")
    {
        CHECK(validate_file_name(str) == 1);
        CHECK(validate_file_name(str2) == 1);
    }
}

TEST_CASE("TESTING STRING VALIDATION")
{
    std::string str;
    CHECK(string_is_empty(str) == true);
    str = "";
    CHECK(string_is_empty(str) == true);
    str = "k";
    CHECK(string_is_empty(str) == false);
}

TEST_CASE("TEST PET FUNCTIONS")
{
    Pet test_pet = create_new_pet("Test", "Pet");
    SUBCASE("Test creating a new pet")
    {
        CHECK(test_pet.name == "Test");
        CHECK(test_pet.type == "Pet");
        CHECK(test_pet.energy == 50);
    }
    feed_pet(test_pet);
    SUBCASE("Test feeding the pet")
    {
        CHECK(test_pet.happiness == 2);
        CHECK(test_pet.fullness == 40);
    }
    play_with_pet(test_pet);
    SUBCASE("Test playing with the pet")
    {
        CHECK(test_pet.energy == 40);
        CHECK(test_pet.happiness == 7);
    }
    put_to_sleep(test_pet);
    SUBCASE("Test sleeping")
    {
        CHECK(test_pet.energy == 65);
        put_to_sleep(test_pet);
        CHECK(test_pet.energy == 90);
        put_to_sleep(test_pet);
        CHECK(test_pet.energy == 100);
        put_to_sleep(test_pet);
        CHECK(test_pet.energy == 100);
    }
}

/*
**  For these to work correctly, you need to change the SAVE_PATH inside pet.h
**  from "saves/" to "../saves/"
*/

/*
TEST_CASE("TESTING FILE EXISTS")
{
    std::string str = "testifilu";
    std::string str2 = "musto1";
    SUBCASE("Files don't exist")
    {
        CHECK(file_exists(str) == 0);
        CHECK(file_exists(str2) == 0);
    }
    str = "musti1";
    str2 = "mirri1";
    SUBCASE("Files do exist (unless u delted them)")
    {
        CHECK(file_exists(str) == 1);
        CHECK(file_exists(str2) == 1);
    }
}
*/
