#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, t;
    set<int> s;
    map<int, int> mp;
    cin >> n >> t;
    int m = 0;
    ll cnt = 0;
    for (int i = 0; i < n; ++i) {
        cin >> t;
        if (i) {
            if (t - *s.begin() > m) {
                m = t - *s.begin();
                cnt = 0;
            }
            if (t - *s.begin() == m) {
                cnt += mp[*s.begin()];
            }
        }
        s.insert(t);
        ++mp[t];
    }
    cout << cnt;
    return 0;
}