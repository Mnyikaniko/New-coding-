

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class LanguageTranslator {
private:
    unordered_map<string, string> dictionary;

public:
    LanguageTranslator() {
        // Predefined translations (English -> Other Language, e.g., Spanish)
        dictionary["hello"] = "hola";
        dictionary["world"] = "mundo";
        dictionary["friend"] = "amigo";
        dictionary["book"] = "libro";
        dictionary["computer"] = "computadora";
        dictionary["food"] = "comida";
        dictionary["love"] = "amor";
        dictionary["day"] = "día";
        dictionary["night"] = "noche";
        dictionary["water"] = "agua";
    }

    void translateWord() {
        string word;
        cout << "\nEnter an English word to translate: ";
        cin >> word;

        // Convert word to lowercase (for case-insensitive matching)
        for (char &c : word) c = tolower(c);

        if (dictionary.find(word) != dictionary.end()) {
            cout << "The translation is: " << dictionary[word] << "\n";
        } else {
            cout << "Sorry, translation not found in the dictionary.\n";
        }
    }

    void addTranslation() {
        string englishWord, translatedWord;
        cout << "\nEnter the English word: ";
        cin >> englishWord;
        cout << "Enter the translated word: ";
        cin >> translatedWord;

        // Convert both to lowercase
        for (char &c : englishWord) c = tolower(c);
        for (char &c : translatedWord) c = tolower(c);

        dictionary[englishWord] = translatedWord;
        cout << "Translation added successfully!\n";
    }
};

int main() {
    LanguageTranslator translator;
    int choice;

    do {
        cout << "\nLanguage Translator\n";
        cout << "1. Translate a Word\n";
        cout << "2. Add a New Translation\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                translator.translateWord();
                break;
            case 2:
                translator.addTranslation();
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