#include <iostream>
#include <vector>
using namespace std;

int main() {
    int rows, cols;

    cout << "Enter no of rows:";
    cin >> rows;

    cout << "Enter no of cols:";
    cin >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols));

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            cout << "Enter an element:";
            cin >> matrix[row][col];
        }
    }

    vector<vector<int>> dp(rows, vector<int>(cols, 0));

    // Initialize first column
    for (int row = 0; row < rows; row++) {
        dp[row][0] = matrix[row][0];
    }

    // Fill remaining columns
    for (int col = 1; col < cols; col++) {
        int largest = 0;
        int secondLargest = 0;

        for (int prevRow = 0; prevRow < rows; prevRow++) {
            if (dp[prevRow][col - 1] > largest) {
                secondLargest = largest;
                largest = dp[prevRow][col - 1];
            }
            else if (dp[prevRow][col - 1] > secondLargest) {
                secondLargest = dp[prevRow][col - 1];
            }
        }

        for (int row = 0; row < rows; row++) {
            dp[row][col] = matrix[row][col] +
                           ((dp[row][col - 1] == largest) ? secondLargest : largest);
        }
    }

    int maxValue = dp[0][cols - 1];

    for (int row = 1; row < rows; row++) {
        if (dp[row][cols - 1] > maxValue) {
            maxValue = dp[row][cols - 1];
        }
    }

    cout << "Maximum Value: " << maxValue << endl;

    return 0;
}
