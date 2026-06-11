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
    int n = s.size();
    vector<int> v(n + 1, 0);
    v[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 7; j >= 5; j--) {
            if (i + j <= n) {
                string ss = string(s.begin() + i, s.begin() + i + j);
                if (ss == "dream" || ss == "dreamer" || ss == "erase" || ss == "eraser") {
                    v[i + j] = max(v[i + j], v[i]);
                }
            }
        }
        // cout << v[i];
    }
    if (v[n] == 1) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

}


