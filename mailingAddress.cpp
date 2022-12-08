// Copyright Cristiano 2022
//
// Created by Cristiano Sellitto
// Created in December 2022
// This program formats a mailing address (Canada Post)

#include <iostream>
#include <string>
#include <algorithm>

std::string FormatMailingAddress(
    std::string fullName,
    std::string streetNumber,
    std::string streetName,
    std::string city,
    std::string province,
    std::string postalCode,
    std::string apartmentNumber
) {
    // Formats a mailing address (Canada Post)

    std::string fullAddress;

    fullAddress = fullName + "\n";
    // Checks if there is an apartment number or not and formats correctly
    if (apartmentNumber != "") {
        fullAddress = fullAddress + apartmentNumber + "-";
    }
    fullAddress = (
        fullAddress
        + streetNumber
        + " "
        + streetName
        + "\n"
        + city
        + " "
        + province
        + "  "
        + postalCode);

    return fullAddress;
}

int main() {
    // Gets input and calls the function

    std::string apartmentOption;
    std::string apartmentNumber;
    std::string fullName;
    std::string streetNumber;
    std::string streetName;
    std::string city;
    std::string province;
    std::string postalCode;
    std::string fullAddress;

    std::cout << "Formats a mailing address";
    std::cout << std::endl;
    std::cout << std::endl;
    // Optional input
    std::cout << "Are you in an apartment? (y/n): ";
    std::getline(std::cin, apartmentOption);
    if (apartmentOption == "y") {
        std::cout << "Enter the apartment number: ";
        std::getline(std::cin, apartmentNumber);
    }
    // Mandatory inputs
    std::cout << "Enter your full name: ";
    std::getline(std::cin, fullName);
    std::cout << "Enter your street number: ";
    std::getline(std::cin, streetNumber);
    std::cout << "Enter your street name: ";
    std::getline(std::cin, streetName);
    std::cout << "Enter your city: ";
    std::getline(std::cin, city);
    std::cout << "Enter your abbreviated province: ";
    std::getline(std::cin, province);
    std::cout << "Enter your postal code: ";
    std::getline(std::cin, postalCode);
    std::cout << std::endl;
    // Make all strings uppercase
    std::for_each(
        fullName.begin(),
        fullName.end(),
        [](char& c) { c = ::toupper(c); });
    std::for_each(
        streetName.begin(),
        streetName.end(),
        [](char& c) { c = ::toupper(c); });
    std::for_each(
        city.begin(),
        city.end(),
        [](char& c) { c = ::toupper(c); });
    std::for_each(
        province.begin(),
        province.end(),
        [](char& c) { c = ::toupper(c); });
    std::for_each(
        postalCode.begin(),
        postalCode.end(),
        [](char& c) { c = ::toupper(c); });
    // Calls function
    if (apartmentOption == "y") {
        fullAddress = FormatMailingAddress(
            fullName,
            streetNumber,
            streetName,
            city,
            province,
            postalCode,
            apartmentNumber);
    } else {
        fullAddress = FormatMailingAddress(
            fullName,
            streetNumber,
            streetName,
            city,
            province,
            postalCode,
            "");
    }
    // Prints the formatted address
    std::cout << fullAddress << std::endl;;

    std::cout << std::endl;
    std::cout << "Done." << std::endl;
}
