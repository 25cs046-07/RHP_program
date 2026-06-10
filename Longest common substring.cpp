#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    string a, c;
    getline(cin, a);
    getline(cin, c);

    int b = a.length();
    int d = c.length();

    vector<vector<int>> mat(b + 1, vector<int>(d + 1, 0));

    int maxLen = 0;
    int endIndex = 0;

    for (int i = 1; i <= b; i++) {
        for (int j = 1; j <= d; j++) {
            if (a[i - 1] == c[j - 1]) {
                mat[i][j] = mat[i - 1][j - 1] + 1;

                if (mat[i][j] > maxLen) {
                    maxLen = mat[i][j];
                    endIndex = i;
                }
            } else {
                mat[i][j] = 0;
            }
        }
    }

    string f = a.substr(endIndex - maxLen, maxLen);

    cout << f << endl;

    return 0;
}
