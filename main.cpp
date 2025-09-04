#include <iostream>
#include <vector>
using namespace std;

char arr[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ    "};
int main() {
    int n; /* number of letters in the word */
    vector<int> pos1, pos2;

    cout << "Guess a word!\n\nStep 1:\n*******\nTable 1:\n\n";

    /* columns */
    for (int i = 0; i < 5; i++) cout << i + 1 << " ";
    cout << "\n";

    /*  first array of letters */
    for (int i = 0; i < 30; i++) {
        if (i % 5 == 0 && i != 0) cout << "\n";
        cout << arr[i] << " ";
    }
    cout << "\n\n";

    cout << "Enter total number of letters in the word: ";
    cin >> n; // <<<< n's value

    pos1.resize(n);
    pos2.resize(n);

    /* asking for a letter from every column */
    for (int i = 0; i < n; i++) {
        cout << "Enter letter " << i + 1 << " column number (1-5): ";
        cin >> pos1[i];
        pos1[i]--; // the counting starts form 0
    }
    /* second array of letters */
    cout << "\nStep 2:\nTable 2:\n\n";
    for (int i = 0; i < 6; i++) cout << i + 1 << " ";
    cout << "\n";

    for (int i = 0; i < n; i++) {
        cout << "\n";
        for (int j = pos1[i]; j < 30; j += 5) {
            cout << arr[j] << " ";
        }
    }
    cout << "\n";

    /* again, asking for a letter from every column */
    for (int i = 0; i < n; i++) {
        cout << "Enter the " << i + 1 << " letter's column number: ";
        cin >> pos2[i];
        pos2[i]--;
    }

    /* guessing the word */
    cout << "Your word is: ";
    for (int i = 0; i < n; i++) {
        cout << arr[pos2[i] * 5 + pos1[i]];
    }
    cout << "\n";

    return 0;
}
