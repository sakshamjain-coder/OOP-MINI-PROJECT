#include <iostream>
#include <string>
using namespace std;

class Transaction
{
public:
    int id;
    string type;
    string category;
    string description;
    double amount;

    Transaction() {}

    Transaction(int i, string t, string c, string d, double a)
    {
        id = i;
        type = t;
        category = c;
        description = d;
        amount = a;
    }
};

class FinancialTracker
{
private:
    Transaction transactions[100];
    int count;

public:
    FinancialTracker()
    {
        count = 0;
    }

    void addTransaction()
    {
        if (count >= 100)
        {
            cout << "Transaction limit reached!\n";
            return;
        }

        string type, category, description;
        double amount;

        cout << "\nEnter Type (Income/Expense): ";
        cin >> type;

        cout << "Enter Category: ";
        cin >> category;

        cout << "Enter Description: ";
        cin.ignore();
        getline(cin, description);

        cout << "Enter Amount: ";
        cin >> amount;

        transactions[count] =
            Transaction(count + 1, type, category, description, amount);

        count++;

        cout << "\nTransaction added successfully!\n";
    }

    void displayTransactions()
    {
        if (count == 0)
        {
            cout << "\nNo transactions available.\n";
            return;
        }

        cout << "\n";
        cout << "===============================================================\n";
        cout << "ID\tType\t\tCategory\tDescription\tAmount\n";
        cout << "===============================================================\n";

        for (int i = 0; i < count; i++)
        {
            cout << transactions[i].id << "\t"
                 << transactions[i].type << "\t\t"
                 << transactions[i].category << "\t\t"
                 << transactions[i].description << "\t"
                 << transactions[i].amount << endl;
        }

        cout << "===============================================================\n";
    }

    double getTotalIncome()
    {
        double income = 0;

        for (int i = 0; i < count; i++)
        {
            if (transactions[i].type == "Income" ||
                transactions[i].type == "income")
            {
                income += transactions[i].amount;
            }
        }

        return income;
    }

    double getTotalExpense()
    {
        double expense = 0;

        for (int i = 0; i < count; i++)
        {
            if (transactions[i].type == "Expense" ||
                transactions[i].type == "expense")
            {
                expense += transactions[i].amount;
            }
        }

        return expense;
    }

    void showSummary()
    {
        double income = getTotalIncome();
        double expense = getTotalExpense();
        double balance = income - expense;

        cout << "\n========== FINANCIAL SUMMARY ==========\n";
        cout << "Total Income   : Rs. " << income << endl;
        cout << "Total Expense  : Rs. " << expense << endl;
        cout << "Current Balance: Rs. " << balance << endl;
        cout << "=======================================\n";
    }

    void searchCategory()
    {
        string category;
        bool found = false;

        cout << "\nEnter category: ";
        cin >> category;

        cout << "\nSearch Results:\n";
        cout << "===============================================================\n";

        for (int i = 0; i < count; i++)
        {
            if (transactions[i].category == category)
            {
                cout << "ID          : " << transactions[i].id << endl;
                cout << "Type        : " << transactions[i].type << endl;
                cout << "Category    : " << transactions[i].category << endl;
                cout << "Description : " << transactions[i].description << endl;
                cout << "Amount      : Rs. " << transactions[i].amount << endl;
                cout << "---------------------------------------------------------------\n";

                found = true;
            }
        }

        if (!found)
        {
            cout << "No transactions found.\n";
        }
    }

    void sortByAmount()
    {
        for (int i = 0; i < count - 1; i++)
        {
            for (int j = 0; j < count - i - 1; j++)
            {
                if (transactions[j].amount >
                    transactions[j + 1].amount)
                {
                    Transaction temp = transactions[j];
                    transactions[j] = transactions[j + 1];
                    transactions[j + 1] = temp;
                }
            }
        }

        cout << "\nTransactions sorted by amount.\n";
    }
};

int main()
{
    FinancialTracker tracker;
    int choice;

    do
    {
        cout << "\n\n";
        cout << "=======================================\n";
        cout << "        FINANCIAL TRACKER\n";
        cout << "=======================================\n";
        cout << "1. Add Transaction\n";
        cout << "2. Display Transactions\n";
        cout << "3. Financial Summary\n";
        cout << "4. Search by Category\n";
        cout << "5. Sort by Amount\n";
        cout << "6. Exit\n";
        cout << "=======================================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            tracker.addTransaction();
            break;

        case 2:
            tracker.displayTransactions();
            break;

        case 3:
            tracker.showSummary();
            break;

        case 4:
            tracker.searchCategory();
            break;

        case 5:
            tracker.sortByAmount();
            break;

        case 6:
            cout << "\nThank you for using Financial Tracker!\n";
            break;

        default:
            cout << "\nInvalid choice! Please try again.\n";
        }

    } while (choice != 6);

    return 0;
}
