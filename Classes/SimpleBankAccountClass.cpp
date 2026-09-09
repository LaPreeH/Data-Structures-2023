#include <iostream>
using namespace std;

class BankAccount {
private:
    string owner;
    double balance;

public:
    // 1. Default constructor
    BankAccount() {
        owner = "Unknown";
        balance = 0.0;
        cout << "Default constructor called!" << endl;
    }

    // 2. Parameterized constructor
    BankAccount(string name, double initialBalance) {
        owner = name;
        balance = initialBalance;
        cout << "Parameterized constructor called!" << endl;
    }

    // 3. Copy constructor
    BankAccount(const BankAccount &acc) {
        owner = acc.owner;
        balance = acc.balance;
        cout << "Copy constructor called!" << endl;
    }

    // Method to display account info
    void display() {
        cout << "Owner: " << owner << ", Balance: $" << balance << endl;
    }

    // Deposit money
    void deposit(double amount) {
        balance += amount;
    }

    // Withdraw money
    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
        } else {
            cout << "Insufficient funds!" << endl;
        }
    }
};

int main() {
    // Using default constructor
    BankAccount acc1;
    acc1.display();

    // Using parameterized constructor
    BankAccount acc2("Alice", 1000.0);
    acc2.display();

    // Deposit and Withdraw
    acc2.deposit(500.0);
    acc2.withdraw(300.0);
    acc2.display();

    // Using copy constructor
    BankAccount acc3 = acc2;
    acc3.display();

    return 0;
}
