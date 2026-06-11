#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    ll n, a, b;
    cin >> n >> a >> b;
    if(a > b) { cout << 0 << endl; return 0;}
    if(n==1 && a!=b) { cout << 0 << endl; return 0;}
    ll mx = b*(n-1) + a;
    ll mn = a*(n-1) + b;
    ll ans = mx-mn + 1;
    cout << ans << endl;
    return 0;
}