#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using ll = long long ;

ll calc(ll a){
    if(a == 0) return 1;
    else return (a*calc(a-1))%1000000007;
}

int main(){
    int n,m; cin >> n >> m;
    ll mod = 1000000007,ans=0;
    if(abs(n-m)>1) ans = 0;
    else if(n == m){
        ans = (((calc(n)*calc(n))%mod)*2)%mod;
    }
    else{
        ans = (calc(max(n,m))*calc(min(n,m)))%mod;
    }
    cout << ans << endl;
}