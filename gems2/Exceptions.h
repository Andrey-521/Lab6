#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <stdexcept>
#include <string>

class GameException : public std::runtime_error {
public:
    explicit GameException(const std::string& msg) : std::runtime_error(msg) {}
};

class OutOfRangeException : public GameException {
public:
    explicit OutOfRangeException(const std::string& msg) : GameException(msg) {}
};

class DeadTargetException : public GameException {
public:
    explicit DeadTargetException(const std::string& msg) : GameException(msg) {}
};

class NoWeaponException : public GameException {
public:
    explicit NoWeaponException(const std::string& msg) : GameException(msg) {}
};

#endif // EXCEPTIONS_H

