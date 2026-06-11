#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < (int)(n); i++)
#define ALL(a) a.begin(), a.end()
#define MOD 1000000007
using namespace std;
using ll = long long;

int main() {
    string A; cin >> A;
    int cnt[26] = {};
    for (auto c : A) cnt[c - 'a']++;

    ll ans = A.size() * (A.size() - 1) / 2 + 1;
    REP(i, 0, 26) ans -= (ll)cnt[i] * (cnt[i] - 1) / 2;
    cout << ans << endl;
    return 0;
}