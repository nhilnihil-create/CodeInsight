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
    string s, t;
    cin >> s >> t;
    string res;
    for (int i = 0; i < s.size(); i++) {
        res.push_back(s[i]);
        if (i < t.size()) {
            res.push_back(t[i]);
        }
    }
    cout << res << endl;
}
