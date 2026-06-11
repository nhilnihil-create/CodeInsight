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

ll comb(ll n,ll k){
    vector<vector<ll>> v(n+1, vector<ll> (n+1,0));
    for (ll i = 0; i < v.size(); i++){
        v[i][0] = 1;
        v[i][i] = 1;
    }

    for (ll i = 2; i < v.size(); i++){
        for (ll j = 1; j < i; j++){
            v[i][j] = v[i-1][j-1] + v[i-1][j];
        }
    }

    return v[n][k];
    
    // nCkを返す
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n,p;
    cin >> n >> p;
    vector<ll> a(n);
    for (ll i = 0;i < n;i++){
        cin >> a[i];
    }

    ll k;
    for (ll i = 0; i < n; i++){
        if (a[i]%2 == 1){
            k++;
        }
    }

    ll s = 0;
    for (ll i = 0; i <= k; i += 2){
        s += comb(k,i);
    }

    ll ans = s;
    rep(i,n-k){
        ans *= 2;
    }

    if (p == 0){
        cout << ans << endl;
    }
    else{
        ll y = pow(2,n);
        cout << y-ans << endl;
    }

}