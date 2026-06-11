#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF = 1'010'000'000'000'000'017LL;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

int main() {
    // AtCoder
    // template
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) {
        cin >> a[i];
        a[i]--;
    }
    ll cnt = 0;
    rep(i, n) {
        if(a[a[i]] == i)
            cnt++;
    }
    cout << cnt / 2 << endl;
}
