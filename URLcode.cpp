

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class URLShortener {
private:
    unordered_map<string, string> shortToLong;
    unordered_map<string, string> longToShort;
    const string baseURL = "http://short.ly/";

    string generateShortURL(const string& longURL) {
        static int id = 1000;
        return baseURL + to_string(id++);
    }

public:
    void createShortURL() {
        string longURL;
        cout << "\nEnter the original URL: ";
        cin.ignore();
        getline(cin, longURL);

        if (longToShort.find(longURL) != longToShort.end()) {
            cout << "Short URL already exists: " << longToShort[longURL] << "\n";
        } else {
            string shortURL = generateShortURL(longURL);
            shortToLong[shortURL] = longURL;
            longToShort[longURL] = shortURL;
            cout << "Short URL created: " << shortURL << "\n";
        }
    }

    void retrieveLongURL() {
        string shortURL;
        cout << "\nEnter the short URL: ";
        cin.ignore();
        getline(cin, shortURL);

        if (shortToLong.find(shortURL) != shortToLong.end()) {
            cout << "Original URL: " << shortToLong[shortURL] << "\n";
        } else {
            cout << "Short URL not found!\n";
        }
    }

    void viewAllURLs() {
        if (shortToLong.empty()) {
            cout << "\nNo URLs have been shortened yet.\n";
            return;
        }

        cout << "\nAll Shortened URLs:\n";
        for (const auto& pair : shortToLong) {
            cout << pair.first << " -> " << pair.second << "\n";
        }
    }
};

int main() {
    URLShortener urlShortener;
    int choice;

    do {
        cout << "\nURL Shortener\n";
        cout << "1. Create Short URL\n";
        cout << "2. Retrieve Original URL\n";
        cout << "3. View All URLs\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                urlShortener.createShortURL();
                break;
            case 2:
                urlShortener.retrieveLongURL();
                break;
            case 3:
                urlShortener.viewAllURLs();
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