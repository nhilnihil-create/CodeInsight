//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using P = pair<int, int>;
using vi = vector<ll>;
using vvi = vector<vi>;



int main() {
    int n;
    cin >> n;
    vi a(n);
    rep(i, n) {
        cin >> a[i];
    }

    ll sum = 0;
    ll ans = 0;
    rep(i, n) {
        if(a[i] == 0) {
            ans += sum/2LL;
            sum = 0LL;
        } else {
            sum += a[i];
        }
    }
    ans += sum/2LL;

    cout << ans << endl;
}