#include <iostream> // Include the library for input and output

using namespace std; // Use the standard namespace

int main() {
    // Declare a variable to store the number
    int number;

    // Prompt the user to enter a number
    cout << "Enter an integer: ";
    cin >> number; // Read the number

    // Check if the number is even or odd
    if (number % 2 == 0) {
        cout << number << " is an even number." << endl; // If divisible by 2
    } else {
        cout << number << " is an odd number." << endl; // If not divisible by 2
    }

    // Return 0 to indicate successful execution
    return 0;
}