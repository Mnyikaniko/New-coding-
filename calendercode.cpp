

#include <iostream>
#include <iomanip>
using namespace std;

class CalendarApplication {
public:
    void displayCalendar(int year, int month) {
        const string months[] = {
            "", "January", "February", "March", "April", "May", "June",
            "July", "August", "September", "October", "November", "December"};
        const int daysInMonth[] = {
            0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        // Check for leap year
        int days = daysInMonth[month];
        if (month == 2 && isLeapYear(year)) {
            days = 29;
        }

        // Get the starting day of the month
        int startDay = getStartDay(year, month);

        // Print the calendar header
        cout << "\n    " << months[month] << " " << year << "\n";
        cout << " Su Mo Tu We Th Fr Sa\n";

        // Print initial spaces for the first row
        for (int i = 0; i < startDay; i++) {
            cout << "   ";
        }

        // Print days of the month
        for (int day = 1; day <= days; day++) {
            cout << setw(3) << day;
            if ((startDay + day) % 7 == 0) {
                cout << endl; // Start a new row after Saturday
            }
        }
        cout << endl;
    }

    void addEvent(int day, int month, int year, const string& event) {
        cout << "Event added on " << day << "/" << month << "/" << year
             << ": " << event << "\n";
    }

private:
    bool isLeapYear(int year) {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    int getStartDay(int year, int month) {
        // Zeller's Congruence Algorithm to find the starting day
        if (month < 3) {
            month += 12;
            year--;
        }
        int K = year % 100;
        int J = year / 100;
        int day = (1 + (13 * (month + 1)) / 5 + K + (K / 4) + (J / 4) + (5 * J)) % 7;
        return (day + 5) % 7; // Adjust for Sunday = 0
    }
};

int main() {
    CalendarApplication calendar;
    int choice;

    do {
        cout << "\nCalendar Application\n";
        cout << "1. Display Calendar for a Month\n";
        cout << "2. Add Event\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int year, month;
                cout << "\nEnter year: ";
                cin >> year;
                cout << "Enter month (1-12): ";
                cin >> month;
                if (month < 1 || month > 12) {
                    cout << "Invalid month! Please try again.\n";
                } else {
                    calendar.displayCalendar(year, month);
                }
                break;
            }
            case 2: {
                int day, month, year;
                string event;
                cout << "\nEnter year: ";
                cin >> year;
                cout << "Enter month (1-12): ";
                cin >> month;
                cout << "Enter day: ";
                cin >> day;
                cout << "Enter event description: ";
                cin.ignore();
                getline(cin, event);
                calendar.addEvent(day, month, year, event);
                break;
            }
            case 3:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}