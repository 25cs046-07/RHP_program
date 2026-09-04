#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, k, testCases, number;

    cin >> testCases;

    while (testCases--) {
        cin >> n >> k;

        int maxDifference = 0;
        int frequency[3 * n + 2] = {};

        for (int i = 0; i < n; i++) {
            cin >> number;
            frequency[number]++;
        }

        for (int startValue = 1; startValue <= 2 * n; startValue++) {
            int currentValue = startValue;

            while (frequency[currentValue] > k) {
                frequency[currentValue + 1] += frequency[currentValue] - 1;
                frequency[currentValue] = 1;
                currentValue++;
            }

            maxDifference = max(maxDifference, currentValue - startValue);
        }

        cout << maxDifference << endl;
    }
}
