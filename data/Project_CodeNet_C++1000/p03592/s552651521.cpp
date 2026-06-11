#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;

#define rep(i,n) for(ll i=0;i<ll(n);i++)
#define YESNO(T) if(T){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}
#define yesno(T) if(T){cout<<"yes"<<endl;}else{cout<<"no"<<endl;}
#define YesNo(T) if(T){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}

const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;
const double pi = 3.14159265358979;



int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n,m,k;
    cin >> n >> m >> k;

    bool ans = false;

    for (ll i = 0; i <= n; i++){
        for (ll j = 0; j <= m; j++){
            ll b = m*i + n*j - 2*i*j;
            if (k == b){
                ans = true;
                goto out;
            }
        }
    }
    out:

    YesNo(ans);

}