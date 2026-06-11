#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, n) for (int i = n-1; i >= 0; i--)
#define all(x) x.begin(), x.end()
using ll = long long;
using pii = pair<int, int>;
const int mod = 1e9+7;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    int cnt = 0;
    rep(i, n) {
        if (i > 0) {
            if (s[i] != s[i-1]) cnt++;
        }
    }
    cout << cnt << endl;
}