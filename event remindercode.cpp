

#include <iostream> 
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

struct Event {
    string name;
    string date; // Format: YYYY-MM-DD
    string time; // Format: HH:MM
};

class EventReminderSystem {
private:
    vector<Event> events;

public:
    void addEvent() {
        Event newEvent;
        cout << "\nEnter event name: ";
        cin.ignore();
        getline(cin, newEvent.name);
        cout << "Enter event date (YYYY-MM-DD): ";
        cin >> newEvent.date;
        cout << "Enter event time (HH:MM): ";
        cin >> newEvent.time;
        events.push_back(newEvent);
        cout << "Event added successfully!\n";
    }

    void viewEvents() {
        if (events.empty()) {
            cout << "\nNo events scheduled.\n";
            return;
        }

        cout << "\nScheduled Events:\n";
        cout << setw(20) << left << "Event Name"
             << setw(15) << "Date"
             << setw(10) << "Time" << endl;
        cout << string(45, '-') << endl;

        for (const auto &event : events) {
            cout << setw(20) << left << event.name
                 << setw(15) << event.date
                 << setw(10) << event.time << endl;
        }
    }

    void deleteEvent() {
        if (events.empty()) {
            cout << "\nNo events to delete.\n";
            return;
        }

        int index;
        viewEvents();
        cout << "\nEnter the event number to delete (1 - " << events.size() << "): ";
        cin >> index;

        if (index < 1 || index > events.size()) {
            cout << "Invalid event number!\n";
            return;
        }

        events.erase(events.begin() + index - 1);
        cout << "Event deleted successfully!\n";
    }
};

int main() {
    EventReminderSystem reminderSystem;
    int choice;

    do {
        cout << "\nEvent Reminder System\n";
        cout << "1. Add Event\n";
        cout << "2. View Events\n";
        cout << "3. Delete Event\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                reminderSystem.addEvent();
                break;
            case 2:
                reminderSystem.viewEvents();
                break;
            case 3:
                reminderSystem.deleteEvent();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
