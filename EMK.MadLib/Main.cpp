#include <iostream>
#include <string>
using namespace std;

struct Inputs {
    string type;
    string input;
};

void DisplayMadLib(const Inputs inputs[], int size) {
    cout << "\nYour Mad Lib:\n";
    cout << "Yesterday, I went to " << inputs[0].input << " and saw a " << inputs[1].input << " " << inputs[2].input << ". ";
    cout << "I asked " << inputs[3].input << " if they wanted to " << inputs[4].input << ", but they said they were busy walking their pet " << inputs[5].input << ".\n";
}

int main() {
    const int SIZE = 6;
    Inputs inputs[SIZE] = {
        {"place", ""},
        {"adjective", ""},
        {"noun", ""},
        {"famous person", ""},
        {"verb", ""},
        {"animal", ""}
    };

    for (int i = 0; i < SIZE; i++) {
        cout << (i + 1) << ". Enter a " << inputs[i].type << ": ";
        cin >> inputs[i].input;
    }

    char fixMistakes;
    do {
        cout << "\nDo you want to fix any mistakes? (y/n): ";
        cin >> fixMistakes;

        if (fixMistakes == 'y' || fixMistakes == 'Y') {
            int entryToFix;
            cout << "Which entry would you like to fix? (1-" << SIZE << "): ";
            cin >> entryToFix;

            if (entryToFix >= 1 && entryToFix <= SIZE) {
                cout << "Enter a " << inputs[entryToFix - 1].type << ": ";
                cin >> inputs[entryToFix - 1].input;
            }
            else {
                cout << "Invalid entry number. Please try again.\n";
            }
        }
    } while (fixMistakes == 'y' || fixMistakes == 'Y');

    DisplayMadLib(inputs, SIZE);

    return 0;
}