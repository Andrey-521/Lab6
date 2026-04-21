#include <iostream>
#include "PasswordUtils.h"
#include "PasswordError.h"

int main() {
    try {
        std::string password = get_password();
        std::cout << "Password accepted: " << password << std::endl;
    }
    catch (const LengthError& e) {
		        std::cerr << e.what() << std::endl;
    }
    catch (const ForbiddenLetterError& e) {
        std::cerr << e.what() << std::endl;
    }
    catch (const RegisterError& e) {
        std::cerr << e.what() << std::endl;
    }
    catch (const DigitError& e) {
        std::cerr << e.what() << std::endl;
    }
    catch (const PasswordError& e) {
        std::cerr << "PasswordError: " << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "std::exception: " << e.what() << std::endl;
    }

    return 0;
}
