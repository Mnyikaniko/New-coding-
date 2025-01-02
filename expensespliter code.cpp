

#include <iostream>
#include <vector>
#include <string>
#include <iomanip> // for setprecision
using namespace std;

class ExpenseSplitter {
private:
    vector<string> participants;
    vector<double> expenses;

public:
    void addParticipant() {
        string name;
        cout << "Enter participant's name: ";
        cin.ignore();
        getline(cin, name);
        participants.push_back(name);
        expenses.push_back(0.0);
        cout << name << " added successfully!\n";
    }

    void addExpense() {
        if (participants.empty()) {
            cout << "No participants added yet!\n";
            return;
        }
        int participantIndex;
        double amount;
        viewParticipants();
        cout << "Enter the participant number who paid: ";
        cin >> participantIndex;

        if (participantIndex < 1 || participantIndex > participants.size()) {
            cout << "Invalid participant number!\n";
            return;
        }

        cout << "Enter the amount spent: ";
        cin >> amount;

        expenses[participantIndex - 1] += amount;
        cout << "Expense recorded successfully!\n";
    }

    void viewParticipants() {
        if (participants.empty()) {
            cout << "No participants to display.\n";
            return;
        }
        cout << "\nParticipants:\n";
        for (size_t i = 0; i < participants.size(); i++) {
            cout << i + 1 << ". " << participants[i] << " (Total Expenses: $"
                 << fixed << setprecision(2) << expenses[i] << ")\n";
        }
    }

    void calculateSplit() {
        if (participants.empty()) {
            cout << "No participants to calculate.\n";
            return;
        }

        double totalExpense = 0.0;
        for (double expense : expenses) {
            totalExpense += expense;
        }

        double perPerson = totalExpense / participants.size();

        cout << "\nExpense Summary:\n";
        cout << "Total Expense: $" << fixed << setprecision(2) << totalExpense << "\n";
        cout << "Each Person Should Pay: $" << fixed << setprecision(2) << perPerson << "\n";

        for (size_t i = 0; i < participants.size(); i++) {
            double balance = expenses[i] - perPerson;
            cout << participants[i] << (balance > 0 ? " is owed $" : " owes $")
                 << fixed << setprecision(2) << abs(balance) << "\n";
        }
    }
};

int main() {
    ExpenseSplitter splitter;
    int choice;

    do {
        cout << "\nExpense Splitter\n";
        cout << "1. Add Participant\n";
        cout << "2. Add Expense\n";
        cout << "3. View Participants\n";
        cout << "4. Calculate Split\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                splitter.addParticipant();
                break;
            case 2:
                splitter.addExpense();
                break;
            case 3:
                splitter.viewParticipants();
                break;
            case 4:
                splitter.calculateSplit();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
