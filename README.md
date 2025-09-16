# BankAccount Class

BankAccount management system in C++.

## Data Dictionary
| Attribute        | Data Type   | Description                        |
|------------------|-------------|------------------------------------|
| accountNum    | std::string | Unique account number              |
| holderName| std::string | The name of the account holder     |
| balance          | double      | The current account balance        |

## Methods List
| Method Signature                               | Return Type | Description                        |
|------------------------------------------------|-------------|------------------------------------|
| BankAccount()                                  | Constructor | Default constructor                |
| BankAccount(string accNum, string name, double bal) | Constructor | Parameterized constructor          |
| getAccountNum() const                       | string      | Returns the account number         |
| getHolderName() const                          | string      | Returns the holder’s name          |
| getBalance() const                             | double      | Returns the account balance        |
| setHolderName(string newName)                  | void        | Updates the holder’s name          |
| deposit(double amount)                         | void        | Deposits money into the account    |
| withdraw(double amount)                        | void        | Withdraws money (if funds available) |
