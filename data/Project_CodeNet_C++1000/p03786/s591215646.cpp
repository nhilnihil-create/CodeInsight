#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    sort(all(a));
    ll s = a[0];
    int t=-1;
    for(int i = 1; i < n; ++i) {
        if(s*2 < a[i]) t = i;
        s+=a[i];
    }
    if(t==-1) cout << n << endl;
    else cout << n-t << endl;
    return 0;
}