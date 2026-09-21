



#include <exception>

#include <iostream>

#include <stdexcept>

#include <string>

using namespace std;


class InsufficientFundsException : public exception {

private:

    double balance;

    double requestedAmount;

public:

    InsufficientFundsException(double currentBalance, double requested)

        : balance(currentBalance), requestedAmount(requested) {}


    const char* what() const noexcept override {

        return "Insufficient balance for withdrawal.";

    }


    double getBalance() const { return balance; }

    double getRequestedAmount() const { return requestedAmount; }

};


class BankAccount {

private:

    int accountNumber;

    string holderName;

    double balance;

public:

    BankAccount(int number, string name, double openingBalance)

        : accountNumber(number), holderName(name), balance(openingBalance) {

        if (openingBalance < 0.0) {

            throw invalid_argument("Opening balance cannot be negative.");

        }

    }


    void deposit(double amount) {

        if (amount <= 0.0) {

            throw invalid_argument("Deposit amount must be positive.");

        }

        balance += amount;

    }


    void withdraw(double amount) {

        if (amount <= 0.0) {

            throw invalid_argument("Withdrawal amount must be positive.");

        }

        if (amount > balance) {

            throw InsufficientFundsException(balance, amount);

        }

        balance -= amount;

    }


    void display() const {

        cout << "Account: " << accountNumber

             << " | Holder: " << holderName

             << " | Balance: Rs. " << balance << endl;

    }

};


int main() {

    try {

        BankAccount account(1001, "Rahul", 5000.0);

        account.deposit(2000.0);

        account.withdraw(1500.0);

        account.withdraw(10000.0);

    } catch (const InsufficientFundsException& error) {

        cout << "Transaction failed: " << error.what() << endl;

        cout << "Available balance: Rs. " << error.getBalance() << endl;

        cout << "Requested amount: Rs. " << error.getRequestedAmount() << endl;

    } catch (const exception& error) {

        cout << "System error: " << error.what() << endl;

    }

}







// Includes the standard exception class and related functionality.
#include <exception>

// Includes input/output functionality such as cout and endl.
#include <iostream>

// Includes standard exception classes such as invalid_argument.
#include <stdexcept>

// Includes the string data type.
#include <string>

// Allows us to use standard library names like cout, string, exception
// without writing std:: before each one.
using namespace std;


// Creates a custom exception class named InsufficientFundsException.
// This exception will be generated when the user tries to withdraw
// more money than the available account balance.
class InsufficientFundsException : public exception {

private:

    // Stores the current balance of the bank account.
    double balance;

    // Stores the amount that the user tried to withdraw.
    double requestedAmount;

public:

    // Constructor of the custom exception class.
    // currentBalance contains the available account balance.
    // requested contains the amount requested for withdrawal.
    InsufficientFundsException(double currentBalance, double requested)

        // Initializes the balance variable with currentBalance.
        // Initializes requestedAmount with requested.
        : balance(currentBalance), requestedAmount(requested) {}


    // Overrides the what() function of the standard exception class.
    // const means this function does not modify the object.
    // noexcept means this function will not throw another exception.
    // override confirms that this function overrides a parent-class function.
    const char* what() const noexcept override {

        // Returns an error message when insufficient funds occur.
        return "Insufficient balance for withdrawal.";

    }


    // Returns the current account balance.
    double getBalance() const { 

        // Sends the balance value back to the calling function.
        return balance; 

    }


    // Returns the amount that the user requested to withdraw.
    double getRequestedAmount() const {

        // Sends the requested withdrawal amount back.
        return requestedAmount;

    }

};


// Creates a BankAccount class to represent a bank account.
class BankAccount {

private:

    // Stores the unique account number.
    int accountNumber;

    // Stores the name of the account holder.
    string holderName;

    // Stores the current amount of money in the account.
    double balance;


public:

    // Constructor used to create a BankAccount object.
    // number represents the account number.
    // name represents the account holder's name.
    // openingBalance represents the initial balance.
    BankAccount(int number, string name, double openingBalance)

        // Initializes accountNumber with number.
        // Initializes holderName with name.
        // Initializes balance with openingBalance.
        : accountNumber(number), holderName(name), balance(openingBalance) {

        // Checks whether the opening balance is negative.
        if (openingBalance < 0.0) {

            // Throws an invalid_argument exception if the balance is negative.
            throw invalid_argument("Opening balance cannot be negative.");

        }

    }


    // Function used to deposit money into the account.
    void deposit(double amount) {

        // Checks whether the deposit amount is zero or negative.
        if (amount <= 0.0) {

            // Throws an exception because the deposit amount must be positive.
            throw invalid_argument("Deposit amount must be positive.");

        }

        // Adds the deposited amount to the existing balance.
        balance += amount;

    }


    // Function used to withdraw money from the account.
    void withdraw(double amount) {

        // Checks whether the withdrawal amount is zero or negative.
        if (amount <= 0.0) {

            // Throws an exception if the withdrawal amount is invalid.
            throw invalid_argument("Withdrawal amount must be positive.");

        }

        // Checks whether the requested amount is greater than
        // the available balance.
        if (amount > balance) {

            // Throws the custom InsufficientFundsException.
            // The current balance and requested amount are passed
            // to the exception object.
            throw InsufficientFundsException(balance, amount);

        }

        // Subtracts the withdrawal amount from the account balance.
        balance -= amount;

    }


    // Function used to display the bank account information.
    // const means this function does not modify the account object.
    void display() const {

        // Prints the account number.
        cout << "Account: " << accountNumber

             // Prints a separator and the account holder's name.
             << " | Holder: " << holderName

             // Prints the separator and current balance.
             << " | Balance: Rs. " << balance

             // Moves the cursor to the next line.
             << endl;

    }

};


// Program execution starts from the main() function.
int main() {

    // Starts a try block.
    // Code that may generate an exception is placed inside it.
    try {

        // Creates a BankAccount object named account.
        // Account number = 1001.
        // Account holder = Rahul.
        // Opening balance = Rs. 5000.
        BankAccount account(1001, "Rahul", 5000.0);


        // Deposits Rs. 2000 into the account.
        // Balance becomes Rs. 7000.
        account.deposit(2000.0);


        // Withdraws Rs. 1500 from the account.
        // Balance becomes Rs. 5500.
        account.withdraw(1500.0);


        // Attempts to withdraw Rs. 10000.
        // Since the balance is only Rs. 5500,
        // InsufficientFundsException will be thrown.
        account.withdraw(10000.0);

    }


    // Catches the custom InsufficientFundsException.
    // The exception object is stored in the reference variable error.
    catch (const InsufficientFundsException& error) {

        // Prints the error message returned by the what() function.
        cout << "Transaction failed: " << error.what() << endl;


        // Prints the balance available in the account.
        cout << "Available balance: Rs. " << error.getBalance() << endl;


        // Prints the amount that the user tried to withdraw.
        cout << "Requested amount: Rs. " << error.getRequestedAmount() << endl;

    }


    // Catches other standard exceptions.
    // This executes if an exception other than
    // InsufficientFundsException is generated.
    catch (const exception& error) {

        // Prints the error message.
        cout << "System error: " << error.what() << endl;

    }

}



