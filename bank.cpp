#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class BankAccount{
    string ID;
    string name;
    double balance;
    public:
    BankAccount(){
        this->ID = "";
        this->name = "";
        this->balance = 0;
    };
    BankAccount(string ID, string name, double balance){
        this->ID = ID;
        this->name = name;
        this->balance = balance;
    };

    void deposit(double m){
        if (m > 0){
            balance += m;
            cout << "Deposited $" << m;
        }
        else{
            cout <<"Invalid deposit amount";
        }
    };
    void withdraw(double m){
        if (m <= balance){
            balance -= m;
            cout << "Withdrawn $+" << m;
        }
        else{
            cout <<"Invalid withdrawal amount or insufficient balance.";
        }
    };
    double checkBalance(){
        return balance;
    };


};

int main(){
    string accountNumber, accountHolderName;
    double initialBalance;

    cout << "Enter account number: ";
    cin >> accountNumber;
    cin.ignore(); // Consume the newline character.

    cout << "Enter account holder name: ";
    getline(cin, accountHolderName);

    cout << "Enter initial balance: ";
    cin >> initialBalance;

    BankAccount account(accountNumber, accountHolderName, initialBalance);

    int choice;
    do {
        cout << "\nMenu:" << endl;
        cout << "1. Deposit Money" << endl;
        cout << "2. Withdraw Money" << endl;
        cout << "3. Check Balance" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                double depositAmount;
                cout << "Enter the amount to deposit: ";
                cin >> depositAmount;
                account.deposit(depositAmount);
                break;
            case 2:
                double withdrawAmount;
                cout << "Enter the amount to withdraw: ";
                cin >> withdrawAmount;
                account.withdraw(withdrawAmount);
                break;
            case 3:
                cout << "Current balance: $" << account.checkBalance() << endl;
                break;
            case 4:
                cout << "Thank you for using our bank services!" << endl;
                break;
            default:
                cout << "Invalid choice. Please select a valid option." << endl;
        }
    } while (choice != 4);
}