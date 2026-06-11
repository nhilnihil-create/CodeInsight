#include <iostream>
#include <vector>
#include <string>
#include <bitset>
#include <cmath>
#include <queue>
#include <iomanip>
#include <algorithm>
#include <stack>
using namespace std;

#define INF 1e18
#define int long long



signed main() {
    string s; cin >> s;

    string substr4 = s.substr(0, 4);
    string substr8 = s.substr(4, 8);
    string ans = substr4 + " " + substr8;

    cout << ans << endl;
}
