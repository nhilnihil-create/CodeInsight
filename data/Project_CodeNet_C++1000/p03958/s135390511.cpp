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

    ll k,t;
    cin >> k >> t;
    vector<ll> a(t);
    for (ll i = 0;i < t;i++){
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());

    ll x = 1;
    for (ll i = 1; i < t; i++){
        x += a[i];
    }

    cout << max((a[0] - x),0LL) << endl;
}