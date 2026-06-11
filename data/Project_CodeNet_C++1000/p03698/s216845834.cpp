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
    unordered_map<char, int> um;
    for (auto ss : s) {
        um[ss]++;
    }
    for (auto p : um) {
        if (p.second > 1) {
            cout << "no" << endl;
            return 0;
        }
    }
    cout << "yes" << endl;
}


