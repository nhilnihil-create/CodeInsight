#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll n, l;
    cin >> n >> l;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    ll last = -1;
    rep(i, 0, n-1) if(a[i] + a[i+1] >= l) last = i;
    if(last == -1) {
        cout << "Impossible" << endl;
        return 0;
    }
    cout << "Possible" << endl;
    rep(i, 0, last) cout << i+1 << endl;
    for(ll i = n-2; i > last; i--) cout << i+1 << endl;
    cout << last + 1 << endl;
    return 0;
}