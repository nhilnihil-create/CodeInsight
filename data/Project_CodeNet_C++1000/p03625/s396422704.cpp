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
    int n;
    cin >> n;
    unordered_map<long long int, int> um;
    long long int a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        um[a]++;
    }
    vector<long long int> v1, v2;
    for (auto p : um) {
        if (p.second >= 2) v1.push_back(p.first);
        if (p.second >= 4) v2.push_back(p.first);
    }
    sort(v1.begin(), v1.end(), greater<long long int>());
    sort(v2.begin(), v2.end(), greater<long long int>());
    long long int res = 0;
    if (v1.size() >= 2) {
        res = max(res, v1[0] * v1[1]);
    }
    if (v2.size() > 0) {
        res = max(res, v2[0] * v2[0]);
    }
    cout << res << endl;
}


