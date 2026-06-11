#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

int findMaxLength(const string& s) {
    unordered_map<int, int> sum_map;
    sum_map[0] = -1; 
    
    int max_len = 0;
    int curr_sum = 0;
    
    for (int i = 0; i < s.length(); ++i) {
        curr_sum += (s[i] == '1') ? 1 : -1;
        
        if (sum_map.find(curr_sum) != sum_map.end()){
            max_len = max(max_len, i - sum_map[curr_sum]);
        } else {
            sum_map[curr_sum] = i;
        }
    }
    
    return max_len;
}

int main() {
    string s;
  cin >>s;
    cout << "Max Length: " << findMaxLength(s) << endl; // Outputs 6
    return 0;
}
