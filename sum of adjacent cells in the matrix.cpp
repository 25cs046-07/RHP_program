#include <iostream>
using namespace std;

int main() {
    int R, C;
    cout << "Enter rows and cols: ";
    cin >> R >> C;

    int grid[100][100]; // fixed-size array
    cout << "Enter matrix elements:\n";
    for (int row = 0; row < R; row++) {
        for (int col = 0; col < C; col++) {
            cin >> grid[row][col];
        }
    }

    int row, col;
    cout << "Enter cell index (row col): ";
    cin >> row >> col;

    int diff[8][2] = {
        {-1,-1}, {-1,0}, {-1,1},
        {0,-1},          {0,1},
        {1,-1},  {1,0},  {1,1}
    };

    long sum = 0;
    for (int i = 0; i < 8; i++) {
        int adjRow = row + diff[i][0];
        int adjCol = col + diff[i][1];
        if (adjRow >= 0 && adjRow < R && adjCol >= 0 && adjCol < C) {
            sum += grid[adjRow][adjCol];
        }
    }

    cout << "Sum of adjacent cells = " << sum << endl;
    return 0;
}
