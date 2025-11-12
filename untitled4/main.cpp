#include <iostream>
#include <string>

using namespace std;

class Bank {
private:
    string name;
    string address;
    string phone;
    double balance = 0.0;

public:
    void openAccount(const string &name, const string &address, const string &phone, const double &initialDeposit) {
        this->name = name;
        this->address = address;
        this->phone = phone;
        balance = initialDeposit;
        cout << "\nAccount successfully created for " << this->name << " with initial deposit of rs." << balance << endl;
        cout << "Current Balance: rs." << balance << endl;
    }

    void depositMoney(double amount) {
        if (amount <= 0) {
            cout << "Deposit amount must be positive!" << endl;
            return;
        }
        balance += amount;
        cout << "Deposited: rs." << amount << " to your account." << endl;
        cout << "Current Balance: rs." << balance << endl;
    }

    void withdrawMoney(double amount) {
        if (amount <= 0) {
            cout << "Withdraw amount must be positive!" << endl;
            return;
        }
        if (amount > balance) {
            cout << "Insufficient balance!" << endl;
        } else {
            balance -= amount;
            cout << "Withdrew: rs." << amount << " from your account." << endl;
            cout << "Current Balance: rs." << balance << endl;
        }
    }

    void displayAccount() const {
        cout << "--------------------------\nACCOUNT DETAILS\n--------------------------" << endl;
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "Phone: " << phone << endl;
        cout << "Current Balance: rs." << balance << endl;
        cout << "--------------------------" << endl;
    }
};

void write_to_logbook(){

}

void read_from_logbook(){

}

int main() {
    cout << "******----BANK OF C PLUS PLUS******----" << endl;

    int choice;
    string name, address, phone;
    double initialDeposit, amount;
    Bank bank;

    while (true) {
        cout << "\n1. Open Account\n2. Deposit Money\n3. Withdraw Money\n4. Display Account\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Ignore remaining newline for getline

        if (choice == 5) {
            cout << "Thank you for banking with us!" << endl;
            break;
        }
        else if (choice == 1) {  // Open Account
            cout << "--------------------------\nACCOUNT CREATION\n--------------------------" << endl;
            cout << "Enter your name: ";
            getline(cin, name);
            cout << "Enter your address: ";
            getline(cin, address);
            cout << "Enter your phone number: ";
            getline(cin, phone);
            cout << "Enter initial deposit amount: ";
            cin >> initialDeposit;
            cin.ignore();
            bank.openAccount(name, address, phone, initialDeposit);
        }
        else if (choice == 2) {  // Deposit Money
            cout << "Enter amount to deposit: ";
            cin >> amount;
            bank.depositMoney(amount);
        }
        else if (choice == 3) {  // Withdraw Money
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            bank.withdrawMoney(amount);
        }
        else if (choice == 4) {  // Display Account
            bank.displayAccount();
        }
        else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
