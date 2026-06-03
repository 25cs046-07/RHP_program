#include <iostream>
#include <string>
using namespace std;

int main() {
    cout << "Enter a string: ";
    string input;
    getline(cin, input);

    int counter = 1;
    int length = input.length();

    for (int mask = 1; mask < (1 << length); mask++) {
        string subset = "";
        for (int bit = 0; bit < length; bit++) {
            if (mask & (1 << bit)) {
                subset += input[bit];
            }
        }
        cout << counter++ << ". " << subset << endl;
    }

    return 0;
}
