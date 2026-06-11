#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int (i)=(0);(i)<(int)(n);++(i))
using ll = long long;
using P = pair< int, int >;

int main() {
    ll k;
    cin >> k;

    vector<ll> a(50);
    rep(i, 50) a[i] = 49 + k / 50;
    k %= 50LL;

    rep(i, k) {
        a[i] += 50+1;
        rep(j, 50) a[j]--;
    }

    cout << 50 << endl;
    for (auto t : a) cout << t << " ";
    cout << endl;
}
