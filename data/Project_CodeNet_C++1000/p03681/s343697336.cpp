#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF = 1LL<<60;

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
    ll a = 1,b = 1;
    if(abs(n-m) > 1){
        cout << 0 << endl;
        return 0;
    }
    for(int i = 1;i <= n;i++){
        a = a * i % MOD;
    }
    
    for(int i = 1;i <= m;i++){
        b = b * i % MOD;
    }
    if(abs(n-m) == 1){
        cout << a*b%MOD;
    }else{
        cout << 2*a*b%MOD;
    }
}

