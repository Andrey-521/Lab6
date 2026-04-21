#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>
#include <string>

class GameException : public std::exception {
protected:
    std::string msg;
public:
    explicit GameException(const std::string& m): msg(m) {}
    const char* what() const noexcept override { return msg.c_str(); }
};

class WeaponException : public GameException {
public:
    explicit WeaponException(const std::string& m): GameException(m) {}
};

class CharacterException : public GameException {
public:
    explicit CharacterException(const std::string& m): GameException(m) {}
};

#endif
