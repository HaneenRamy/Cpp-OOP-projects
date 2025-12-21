#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// Represents a single bank account
class Account {
public:
    string ownerName;          // Account holder name
    long long accountNumber;   // Unique account number
    double balance;            // Current balance

    // Constructor to initialize account data
    Account(string name, long long accNum, double bal)
        : ownerName(name), accountNumber(accNum), balance(bal) {
    }
};

// Main bank system class
class BankSystem {
private:
    vector<Account> accounts;  // Stores all bank accounts

    // Finds an account by its account number
    // Returns index if found, otherwise -1
    int findAccount(long long accNum) {
        for (size_t i = 0; i < accounts.size(); i++) {
            if (accounts[i].accountNumber == accNum) {
                return i;
            }
        }
        return -1;
    }

public:
    // Constructor: initializes system with sample accounts
    BankSystem() {
        accounts.push_back(Account("Haneen Ramy", 101, 2500.00));
        accounts.push_back(Account("Nour Sarhan", 102, 1200.50));
        accounts.push_back(Account("Hana Hoseiny", 103, 75.25));
        accounts.push_back(Account("Salma Amin", 104, 900.00));
        accounts.push_back(Account("Rawan Amr", 105, 1800.00));

        cout << fixed << setprecision(2); // Format money output
    }

    // Displays the main menu
    void displayMenu() {
        cout << "\n--- Bank Management System Menu ---\n";
        cout << "1. View All Accounts\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
    }

    // Displays all active accounts
    void viewAccounts() {
        cout << "\n--- Active Accounts ---\n";
        for (const auto& acc : accounts) {
            cout << "Owner: " << acc.ownerName
                << " | Account No: " << acc.accountNumber
                << " | Balance: $" << acc.balance << endl;
        }
    }

    // Deposits money into an account using account number
    void depositMoney() {
        long long accNum;
        double amount;

        cout << "Enter account number: ";
        cin >> accNum;

        int index = findAccount(accNum);
        if (index == -1) {
            cout << "Account not found.\n";
            return;
        }

        cout << "Enter deposit amount: $";
        cin >> amount;

        // Validate amount input
        if (cin.fail() || amount <= 0) {
            cin.ignore();
            cout << "Invalid amount.\n";
            return;
        }

        accounts[index].balance += amount;
        cout << "Deposit successful. New balance: $"
            << accounts[index].balance << endl;
    }

    // Withdraws money from an account using account number
    void withdrawMoney() {
        long long accNum;
        double amount;

        cout << "Enter account number: ";
        cin >> accNum;

        int index = findAccount(accNum);
        if (index == -1) {
            cout << "Account not found.\n";
            return;
        }

        cout << "Enter withdrawal amount: $";
        cin >> amount;

        // Validate amount input
        if (cin.fail() || amount <= 0) {
            cin.ignore();
            cout << "Invalid amount.\n";
            return;
        }

        // Check sufficient balance
        if (accounts[index].balance < amount) {
            cout << "Insufficient funds. Current balance: $"
                << accounts[index].balance << endl;
            return;
        }

        accounts[index].balance -= amount;
        cout << "Withdrawal successful. New balance: $"
            << accounts[index].balance << endl;
    }

    // Starts the bank system menu loop
    void start() {
        int choice;

        do {
            displayMenu();
            cin >> choice;
            // Validate menu input
            if (cin.fail()) {
                cin.ignore();
                cout << "Invalid input.\n";
                continue;
            }

            switch (choice) {
            case 1:
                viewAccounts();
                break;
            case 2:
                depositMoney();
                break;
            case 3:
                withdrawMoney();
                break;
            case 4:
                cout << "Thank you for using the Bank System.\n";
                break;
            default:
                cout << "Invalid choice.\n";
            }

        } while (choice != 4);
    }
};

int main() {
    BankSystem bank;   // Create bank system object
    bank.start();      // Start the system
    return 0;
}
