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
    string res;
    for (auto ss : s) {
        if (ss == 'B') {
            if (res.size() > 0) res.pop_back();
        } else {
            res.push_back(ss);
        }
    }
    cout << res << endl;
}
