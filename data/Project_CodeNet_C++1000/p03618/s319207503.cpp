#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; i >= a; i--)
#define int long long
using pint = pair<int, int>;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int dxx[8] = {1, 1, 1, 0, 0, -1, -1, -1}, dyy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

signed main() {
    string s;
    cin >> s;
    int n = s.size();
    map<char, int> mp;
    rep (i, 0, n) mp[s[i]]++;
    int ans = n * (n - 1) / 2;
    for (auto p : mp) {
        ans -= p.second * (p.second - 1) / 2;
    }
    cout << ++ans << "\n";
}