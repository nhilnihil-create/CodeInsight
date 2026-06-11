#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;
#define int long long
constexpr int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
constexpr int lcm(int a, int b) { return a / gcd(a, b) * b; }

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;
    vector<int> t(n);
    for (int i = 0; i < n; i++) cin >> t[i];

    int cumlcm = 1;
    for (auto &&i : t) {
        cumlcm = lcm(i, cumlcm);
    }

    const int ans = cumlcm;
    cout << ans << endl;
}
