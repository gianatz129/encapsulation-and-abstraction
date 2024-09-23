#include <iostream> 
#include <cstdlib> // For clearing sytem
#include <string> // For validating text input
#include <cctype> // For the use of isdigit

using namespace std;

bool isNumber(const string &str) // Function that validates only for numbers
{
    for (char const &c : str)
    {
        if (!isdigit(c))
        {
            return false;
        }
    }
    return true;
}

class AccountMenu // Base class 
{
public:
    virtual void subMenu() = 0; // Virtual function (abstraction)
    virtual void subMenu2() = 0; // Virtual function (abstraction)
};

class Account : public AccountMenu // Derived class for a generic account
{
private:
    int balance;  // For Savings Account (encapsulation)
    int balance2; // For Current Account (encapsulation)

public: // Initialize balances for Savings and Current accounts
    Account() : balance(1000), balance2(0) {}

    // Savings Account menu
    void subMenu() override
    {
        int choice;
        string input;
        int amount;

        do
        {
            system("pause");
            system("CLS");
            cout << "|===================Savings Account==================|" << endl;
            cout << " 1 - Deposit" << endl;
            cout << " 2 - Withdraw" << endl;
            cout << " 3 - Check Balance" << endl;
            cout << " 4 - Go back to Main Menu" << endl;
            cout << "|====================================================|" << endl;
            cout << " Enter your choice: "; cin >> input;

            while (!isNumber(input)) // Input validation for choice
            {
                cout << " Invalid input. Please enter a valid number." << endl;
                cout << " Enter your choice: "; cin >> input;
            }
            choice = stoi(input); // Convert valid string to integer

            switch (choice) // User to select choice
            {
            case 1:
                cout << " Enter deposit amount: P"; cin >> input;
                while (!isNumber(input))
                {
                    cout << " Invalid amount. Please enter a valid number: P"; cin >> input;
                }
                amount = stoi(input); // Convert valid string to integer
                deposit(amount, balance); // Deposit to Savings
                break;
            case 2:
                cout << " Enter withdrawal amount: P"; cin >> input;
                while (!isNumber(input))
                {
                    cout << " Invalid amount. Please enter a valid number: P"; cin >> input;
                }
                amount = stoi(input); // Convert valid string to integer
                withdraw(amount, balance); // Withdraw from Savings
                break;
            case 3:
                cout << " Current balance (Savings): P" << balance << endl;
                break;
            case 4:
                cout << " Returning to Main Menu..." << endl;
                break;
            default:
                cout << " Invalid choice! Please try again." << endl;
            }
        } while (choice != 4); // Loop until user selects Exit 
    }

    // Current Account menu
    void subMenu2() override
    {
        int choice;
        string input;
        int amount;

        do
        {
            system("pause");
            system("CLS");
            cout << "|===================Current Account==================|" << endl;
            cout << " 1 - Deposit" << endl;
            cout << " 2 - Withdraw" << endl;
            cout << " 3 - Check Balance" << endl;
            cout << " 4 - Go back to Main Menu" << endl;
            cout << "|====================================================|" << endl;
            cout << " Enter your choice: "; cin >> input;

            while (!isNumber(input)) // Input validation for choice
            {
                cout << " Invalid input. Please enter a valid number." << endl;
                cout << " Enter your choice: "; cin >> input;
            }
            choice = stoi(input); // Convert valid string to integer

            switch (choice) // User to select choice
            {
            case 1:
                cout << " Enter deposit amount: P"; cin >> input;
                while (!isNumber(input))
                {
                    cout << " Invalid amount. Please enter a valid number: P"; cin >> input;
                }
                amount = stoi(input); // Convert valid string to integer
                deposit(amount, balance2); // Deposit to Current
                break;
            case 2:
                cout << " Enter withdrawal amount: P"; cin >> input;
                while (!isNumber(input))
                {
                    cout << " Invalid amount. Please enter a valid number: P"; cin >> input;
                }
                amount = stoi(input); // Convert valid string to integer
                withdraw(amount, balance2); // Withdraw from Current
                break;
            case 3:
                cout << " Current balance (Current): P" << balance2 << endl;
                break;
            case 4:
                cout << " Returning to Main Menu..." << endl;
                break;
            default:
                cout << " Invalid choice! Please try again." << endl;
            }
        } while (choice != 4); // Loop until user selects Exit
    }

    // Calls the encapsulated data
    void deposit(int amount, int &accountBalance) // Function to deposit to the correct account balance
    {
        if (amount > 0)
        {
            accountBalance += amount;
            cout << " Deposit successful." << endl;
        }
        else
        {
            cout << " Deposit failed. Please enter a valid amount." << endl;
        }
    }

    // Calls the encapsulated data
    void withdraw(int amount, int &accountBalance) // Function to withdraw from the correct account balance
    {
        if (amount > 0 && amount <= accountBalance)
        {
            accountBalance -= amount;
            cout << " Withdrawal successful." << endl;
        }
        else
        {
            cout << " Withdrawal failed. Insufficient funds or invalid amount." << endl;
        }
    }
};

// Display main menu
int main()
{
    Account myAccount;
    string input;
    int choice;

    do
    {
        system("pause");
        system("CLS");
        cout << "|====================|PAY AGILA|===================|" << endl;
        cout << "|---------------------Main Menu--------------------|" << endl;
        cout << " 1 - Savings Account" << endl;
        cout << " 2 - Current Account" << endl;
        cout << " 3 - Exit" << endl;
        cout << "|==================================================|" << endl;
        cout << " Enter your choice: "; cin >> input;

        while (!isNumber(input)) // Input validation for main menu
        {
            cout << " Invalid input. Please enter a valid number." << endl;
            cout << " Enter your choice: "; cin >> input;
        }
        choice = stoi(input); // Convert valid string to integer

        switch (choice) // User to select choice
        {
        case 1:
            cout << " You selected Savings Account." << endl;
            myAccount.subMenu();
            break;
        case 2:
            cout << " You selected Current Account." << endl;
            myAccount.subMenu2();
            break;
        case 3:
            cout << " Exiting the program." << endl;
            break;
        default:
            cout << " Invalid choice! Please try again." << endl;
        }

    } while (choice != 3); // Loop until user selects Exit 

    return 0;
}
