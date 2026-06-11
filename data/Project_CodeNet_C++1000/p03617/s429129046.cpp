#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    int q, h, s, d, n;
    cin >> q >> h >> s >> d >> n;
    h = min(h, 2*q);//500ml
    s = min(s, 2*h);//1l
    d = min(d, 2*s);//2l
    ll ans = (ll)(n/2)*d + (n%2)*s;
    cout << ans << endl;
    return 0;
}