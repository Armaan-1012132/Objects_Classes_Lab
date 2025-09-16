#include <iostream>
#include <string>
#include <vector>
using namespace std;

class BankAccount {
private:
    string accountNum;
    string holderName;
    double balance;

public:
    // Default constructor
    BankAccount() : accountNum("N/A"), holderName("Unknown"), balance(0.0) {}

    // Parameterized constructor
    BankAccount(string accNum, string holder, double bal)
        : accountNum(accNum), holderName(holder), balance(bal) {}

    // Getters
    string getAccountNum() const { return accountNum; }
    string getholderName() const { return holderName; }
    double getBalance() const { return balance; }

    // Setter
    void setholderName(string newName) { holderName = newName; }

    // Deposit
    void deposit(double amount) {
        if (amount > 0) balance += amount;
        else cout << "Invalid deposit amount!!\n";
    }

    // Withdraw
    void withdraw(double amount) {
        if (amount > balance) cout << "Insufficient funds!!\n";
        else if (amount <= 0) cout << "Invalid withdraw amount!!\n";
        else balance -= amount;
    }
};

int main() {
    vector<BankAccount> accounts;
    int choice;

    do {
        cout << "\n--- BestBank Menu Ever ---\n";
        cout << "1. Add New Account\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Show Accounts\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1: {
                string accNum, name;
                double bal;
                cout << "Enter account number: ";
                cin >> accNum;
                cout << "Enter account holder name: ";
                cin >> name;
                cout << "Enter initial balance: ";
                cin >> bal;
                accounts.push_back(BankAccount(accNum, name, bal));
                break;
            }
            case 2: {
                string accNum;
                double amt;
                cout << "Enter account number: ";
                cin >> accNum;
                cout << "Enter deposit amount: ";
                cin >> amt;
                bool found = false;
                for (auto &acc : accounts) {
                    if (acc.getAccountNum() == accNum) {
                        acc.deposit(amt);
                        found = true;
                        break;
                    }
                }
                if (!found) cout << "Account does not exist.\n";
                break;
            }
            case 3: {
                string accNum;
                double amt;
                cout << "Enter account number: ";
                cin >> accNum;
                cout << "Enter withdraw amount: ";
                cin >> amt;
                bool found = false;
                for (auto &acc : accounts) {
                    if (acc.getAccountNum() == accNum) {
                        acc.withdraw(amt);
                        found = true;
                        break;
                    }
                }
                if (!found) cout << "Account does not exist.\n";
                break;
            }
            case 4:
                for (auto &acc : accounts) {
                    cout << acc.getAccountNum() << " | "
                         << acc.getholderName() << " | "
                         << acc.getBalance() << "\n";
                }
                break;
            case 5:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Nope.\n";
        }
    } while (choice != 5);

    return 0;
}
