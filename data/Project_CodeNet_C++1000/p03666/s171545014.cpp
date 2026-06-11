#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
typedef long long ll;

int main(){
    ll n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    ll f = b - a;
    bool can = false;
    rep(m,n-1){
        ll l = -d*m + (n-1-m)*c;
        ll r = -c*m + (n-1-m)*d;
        if(l <= f && f <= r) can = true;
    }
    cout << (can? "YES" : "NO") << endl;
    return 0;
}