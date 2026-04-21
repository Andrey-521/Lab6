#include "PasswordUtils.h"
#include <iostream>
#include <cctype>
#include <unordered_set>

std::string get_password() {
    std::cout << "Enter your password: ";
    std::string pwd;
    if (!std::getline(std::cin, pwd)) {
        return std::string();
    }

    const std::unordered_set<char> forbidden = {'l', 'I', '1', 'o', 'O', '0'};

    for (char ch : pwd) {
        if (forbidden.find(ch) != forbidden.end()) {
            throw ForbiddenLetterError();
        }
    }

    if (pwd.size() < 9) {
        throw LengthError();
    }

    bool has_alpha = false;
    bool has_upper = false;
    bool has_lower = false;
    for (char ch : pwd) {
        if (std::isalpha(static_cast<unsigned char>(ch))) {
            has_alpha = true;
            if (std::isupper(static_cast<unsigned char>(ch))) has_upper = true;
            if (std::islower(static_cast<unsigned char>(ch))) has_lower = true;
        }
    }
    if (has_alpha && !(has_upper && has_lower)) {
        throw RegisterError();
    }
    bool has_digit = false;
    for (char ch : pwd) {
        if (std::isdigit(static_cast<unsigned char>(ch))) {
            has_digit = true;
            break;
        }
    }
    if (!has_digit) {
        throw DigitError();
    }

    return pwd;
}
