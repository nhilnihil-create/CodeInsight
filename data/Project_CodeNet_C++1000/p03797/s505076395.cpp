#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll GCD(ll x,ll y){
    if(y == 0) return x;
    else return GCD(y,x%y);
}

ll LCM(ll a,ll b){
    return a / GCD(a,b) * b;
}

const int MOD = 1000000007;

int main() {
    ll n,m; cin >> n >> m;
    ll cnt = min(n,m/2);
    m-=cnt*2;
    if(m >= 4){
     cnt+=m/4;
    }
    cout << cnt;
}


