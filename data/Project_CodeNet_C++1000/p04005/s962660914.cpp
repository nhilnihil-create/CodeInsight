#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    ll a, b, c;
    cin >> a >> b >> c;
    if(a%2==0 || b%2==0 || c%2==0){
        cout << 0 << endl;
        return 0;
    }
    int mx = max(a, max(b, c));
    ll ans = min(a*b, min(b*c, c*a));
    cout << ans << endl;
    return 0;
}