#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll n;
    cin >> n;
    vector<ll> a(n), acc(n+1, 0);
    rep(i, 0, n) cin >> a[i];
    sort(a.begin(), a.end());
    rep(i, 0, n) acc[i+1] = acc[i] + a[i];
    ll ans = 1;
    rep(i, 1, n) {
        if(a[i] <= 2 * acc[i]) {
            ans++;
        } else {
            ans = 1;
        }
    }
    cout << ans << endl;
    return 0;
}