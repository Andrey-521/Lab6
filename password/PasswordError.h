#pragma once
#include <exception>
#include <string>

class PasswordError : public std::exception {
protected:
    std::string message_;
public:
    explicit PasswordError(const std::string& msg);
    virtual const char* what() const noexcept override;
    virtual ~PasswordError() noexcept;
};

class LengthError : public PasswordError {
public:
    LengthError();
};

class RegisterError : public PasswordError {
public:
    RegisterError();
};

class DigitError : public PasswordError {
public:
    DigitError();
};

class ForbiddenLetterError : public PasswordError {
public:
    ForbiddenLetterError();
};
