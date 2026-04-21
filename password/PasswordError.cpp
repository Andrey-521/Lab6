#include "PasswordError.h"

PasswordError::PasswordError(const std::string& msg)
    : message_(msg)
{}

const char* PasswordError::what() const noexcept {
    return message_.c_str();
}

PasswordError::~PasswordError() noexcept = default;

LengthError::LengthError()
    : PasswordError("LengthError: The password length is less than 9 characters.")
{}

RegisterError::RegisterError()
    : PasswordError("RegisterError: all alphabetic characters of the same case.")
{}

DigitError::DigitError()
    : PasswordError("DigitError: There are no numbers in the password.")
{}

ForbiddenLetterError::ForbiddenLetterError()
    : PasswordError("ForbiddenLetterError: the password contains prohibited characters (lI, 1, o, O, 0).")
{}
