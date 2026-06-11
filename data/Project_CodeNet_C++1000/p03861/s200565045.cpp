#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    ll a, b, x;
    cin >> a >> b >> x;
    ll A = a/x;
    ll B = b/x;
    ll ans = B - A;
    if(a%x==0) ans++;
    cout << ans << endl;
    return 0;
}