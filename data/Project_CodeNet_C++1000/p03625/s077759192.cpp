#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    sort(a.begin(), a.end());
    a.push_back(0);

    vector<pair<ll, int>> more_than2;
    int cnt = 0;
    rep(i, n) {
        cnt++;
        if (a[i] != a[i + 1]) {
            if (cnt >= 2) more_than2.emplace_back(a[i], cnt);
            cnt = 0;
        }
    }

    if (more_than2.empty() || more_than2.size() == 1 && more_than2[0].second < 4) cout << 0 << endl;
    else {
        auto p = more_than2[more_than2.size() - 1];
        if (p.second >= 4) {
            cout << p.first * p.first << endl;
        } else {
            cout << more_than2[more_than2.size() - 1].first * more_than2[more_than2.size() - 2].first;
        }
    }

    return 0;
}