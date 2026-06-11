#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < ll(n); i++)

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> abs(n);
    rep(i, n) cin >> abs[i].first >> abs[i].second;

    sort(abs.begin(), abs.end());
    cout << abs[n - 1].first + abs[n - 1].second << endl;
}
