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
    long long int n = s.size();
    long long int res = n * (n - 1) / 2;
    vector<int> v(26, 0);
    for (int i = 0; i < n; i++) {
        res -= v[s[i] - 'a'];
        v[s[i] - 'a']++;
    }
    cout << res + 1 << endl;
}
