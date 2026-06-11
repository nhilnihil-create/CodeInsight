#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define put(i) cout<<fixed<<i<<endl
using namespace std;
using ll = long long;

int main(){
    ll n, m; cin >> n >> m;

    if(n >= m){
        put(m/2);
    }else{
        ll ans = 0;
        ans = n;
        m -= n * 2;
        ans += m / 4;
        put(ans);
    }
}