#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1LL << 60;
const int MAX = 1000000010;
const ll MOD = 1000000007;
const double PI = acos(-1);

bool ok(string s) {
    int n = s.size();
    if (n % 2 == 1) return false;
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n / 2 + i]) return false;
    }

    return true;
}

int solve(string s) {
    int n = s.size();
    int i = 0;
    while (!s.empty()) {
        s.pop_back();
        i++;
        if (ok(s)) return n - i;
    }
}

int main() {
    string s; cin >> s;
    int ans = solve(s);
    cout << ans << endl;
    return 0;
}