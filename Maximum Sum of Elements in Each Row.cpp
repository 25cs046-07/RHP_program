#include <iostream>
using namespace std;

int main() {
    int rows, cols;

    cout << "Enter no of rows and cols:";
    cin >> rows >> cols;

    int matrix[rows][cols], dp[rows][cols];

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            cout << "Enter an element:";
            cin >> matrix[row][col];

            if (row == 0) {
                dp[row][col] = matrix[row][col];
            }
        }
    }

    for (int row = 1; row < rows; row++) {
        int largest = 0;
        int secondLargest = 0;

        for (int prevCol = 0; prevCol < cols; prevCol++) {
            if (largest < dp[row - 1][prevCol]) {
                secondLargest = largest;
                largest = dp[row - 1][prevCol];
            }
            else if (dp[row - 1][prevCol] > secondLargest) {
                secondLargest = dp[row - 1][prevCol];
            }
        }

        for (int col = 0; col < cols; col++) {
            dp[row][col] = matrix[row][col] +
                           ((dp[row - 1][col] == largest) ? secondLargest : largest);
        }
    }

    int maxSum = dp[rows - 1][0];

    for (int col = 0; col < cols; col++) {
        if (dp[rows - 1][col] > maxSum) {
            maxSum = dp[rows - 1][col];
        }
    }

    cout << "Maximum Sum:" << maxSum << endl;

    return 0;
}
