#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <queue>
#include <cmath>
using namespace std;


int main() {
    string s;
    cin >> s;
    vector<int> v(26, 0);
    for (auto ss : s) {
        v[ss - 'a'] = 1;
    }
    for (int i = 0; i < 26; i++) {
        if (v[i] == 0) {
            cout << (char)(i + 'a') << endl;
            return 0;
        }
    }
    cout << "None" << endl;
}


