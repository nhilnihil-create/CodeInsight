#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(v) (v).begin(), (v).end()
using ll = long long;
constexpr int INF = 1e9;
constexpr long long LINF = 1e18;
constexpr long long MOD = 1e9 + 7;

signed main() {
    string s;
    cin >> s;
    int p = s.size();
    if (s.front() == s.back()) p++;
    p %= 2;
    cout << (p ? "First" : "Second") << endl;
    return 0;
}