#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main() {
    string S;
    cin >> S;
    ll N = S.length();
    vector<ll> cnt(26, 0);
    for (char& c : S) {
        cnt[c - 'a']++;
    }

    ll ans = N * (N - 1) / 2;
    for (ll& c : cnt) {
        ans -= c * (c - 1) / 2;
    }
    cout << ans + 1 << endl;
}
