#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF = 1LL<<60;
//ll GCD(ll x,ll y){
//    if(y == 0) return x;
//    else return GCD(y,x%y);
//}

ll GCD(ll x,ll y){
    if(y == 0) return x;
    else return GCD(y,x%y);
}

ll LCM(ll a,ll b){
    return a / GCD(a,b) * b;
}

const int MOD = 1000000007;



int main() {
    ll n; cin >> n;
    if(n <= 6){
        cout << 1;
    }else if(n <= 11){
        cout << 2;
    }else{
        if(n%11 == 0){
            cout << (ll)(n/11)*2;
        }else if(n%11 <= 6){
            cout << (ll)(n/11)*2+1;
        }else{
            cout << (ll)(n/11)*2+2;
        }
    }
}
