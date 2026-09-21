



#include <iostream>

#include <stdexcept>

#include <string>

using namespace std;


class InputValidator {

public:

    static void validateAge(int age) {

        if (age < 0 || age > 120) {

            throw invalid_argument("Invalid age.");

        }

    }

    static void validateName(const string& name) {

        if (name.empty()) {

            throw invalid_argument("Name cannot be empty.");

        }

    }

};


int main() {

    try {

        InputValidator::validateAge(25);

        InputValidator::validateName("Rahul");

        cout << "Input is valid." << endl;

    } catch (const exception& error) {

        cout << "Validation error: " << error.what() << endl;

    }

}

