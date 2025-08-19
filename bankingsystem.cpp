#include <iostream>
using namespace std;

class Account {
private:
    int accNo;
    string name;
    double balance;

public:
    void create(int no, string n, double b) {
        accNo = no;
        name = n;
        balance = b;
    }

    int getAccNo() { return accNo; }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit Successful. Balance = " << balance << endl;
        } else {
            cout << "Invalid amount!\n";
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawal Successful. Balance = " << balance << endl;
        } else {
            cout << "Insufficient balance or invalid amount!\n";
        }
    }

    void display() {
        cout << "\n--- Account Info ---\n";
        cout << "Account No: " << accNo << endl;
        cout << "Name: " << name << endl;
        cout << "Balance: " << balance << endl;
    }
};

int main() {
    Account accounts[50];
    int total = 0;
    int choice;

    do {
        cout << "\n--- Banking System ---\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Show Account\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int no; string n; double bal;
            cout << "Enter Account No: ";
            cin >> no;
            cout << "Enter Name: ";
            cin.ignore();
            getline(cin, n);
            cout << "Enter Initial Balance: ";
            cin >> bal;
            accounts[total].create(no, n, bal);
            total++;
            cout << "Account Created Successfully!\n";
        }
        else if (choice == 2) {
            int no; double amt;
            cout << "Enter Account No: ";
            cin >> no;
            for (int i = 0; i < total; i++) {
                if (accounts[i].getAccNo() == no) {
                    cout << "Enter Amount: ";
                    cin >> amt;
                    accounts[i].deposit(amt);
                }
            }
        }
        else if (choice == 3) {
            int no; double amt;
            cout << "Enter Account No: ";
            cin >> no;
            for (int i = 0; i < total; i++) {
                if (accounts[i].getAccNo() == no) {
                    cout << "Enter Amount: ";
                    cin >> amt;
                    accounts[i].withdraw(amt);
                }
            }
        }
        else if (choice == 4) {
            int no;
            cout << "Enter Account No: ";
            cin >> no;
            for (int i = 0; i < total; i++) {
                if (accounts[i].getAccNo() == no) {
                    accounts[i].display();
                }
            }
        }
        else if (choice == 5) {
            cout << "Exiting... Thanks!\n";
        }
        else {
            cout << "Invalid Choice!\n";
        }
    } while (choice != 5);

    return 0;
}