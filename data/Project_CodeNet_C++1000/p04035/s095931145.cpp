#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll n, l;
    cin >> n >> l;
    vector<ll> a(n), b(n-1);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n-1) b[i] = a[i] + a[i+1];
    auto mx = max_element(b.begin(), b.end());
    if(*mx < l){
        cout << "Impossible" << endl;
        return 0;
    }
    cout << "Possible" << endl;
    auto pos = mx - b.begin();
    rep(i, 0, pos) cout << i+1 << endl;
    for(ll i = n-2; i >= pos; i--) cout << i+1 << endl;
    return 0;
}