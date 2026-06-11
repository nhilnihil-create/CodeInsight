#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const int inf = 1e9;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, b, a) for (int i = a - 1; i >= b; i--)
using Graph = vector<vector<int>>;
using pint = pair<int, int>;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int dxx[8] = {1, 1, 1, 0, 0, -1, -1, -1}, dyy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main() {
    int h, w;
    cin >> h >> w;
    map<char, int> mp;
    rep (i, 0, h * w) {
        char a;
        cin >> a;
        mp[a]++;
    }
    int odd = 0, over4 = 0;
    bool ans = 1;
    for (auto p : mp) {
        if (p.second % 2 == 1) odd++;
        if (p.second > 3) {
            over4 += p.second / 4;
        }
    }
    if (h % 2 == 1 && w % 2 == 1) {
        if (odd > 1) {
            ans = 0;
        }
    } else {
        if (odd > 0) {
            ans = 0;
        }
    }
    if ((h / 2) * (w / 2) > over4) {
        ans = 0;
    }
    if (ans) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}