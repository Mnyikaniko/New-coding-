

#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

class StopwatchAndTimer {
public:
    void stopwatch() {
        cout << "\nStopwatch started. Press Enter to stop...\n";
        cin.ignore();
        auto start = chrono::high_resolution_clock::now();
        cin.get(); // Wait for Enter key
        auto stop = chrono::high_resolution_clock::now();
        chrono::duration<double> elapsed = stop - start;
        cout << "Elapsed time: " << elapsed.count() << " seconds\n";
    }

    void timer() {
        int seconds;
        cout << "\nEnter the timer duration (in seconds): ";
        cin >> seconds;

        cout << "Timer started for " << seconds << " seconds...\n";
        for (int i = seconds; i > 0; i--) {
            cout << i << " seconds remaining...\r";
            cout.flush();
            this_thread::sleep_for(chrono::seconds(1));
        }

        cout << "Time's up!\n";
    }
};

int main() {
    StopwatchAndTimer tool;
    int choice;

    do {
        cout << "\nStopwatch and Timer\n";
        cout << "1. Stopwatch\n";
        cout << "2. Timer\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cin.ignore(); // To handle Enter key from the menu input
                tool.stopwatch();
                break;
            case 2:
                tool.timer();
                break;
            case 3:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}