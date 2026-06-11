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

    ll n,c,k;
    cin >> n >> c >> k;
    vector<ll> t(n);
    for (ll i = 0;i < n;i++){
        cin >> t[i];
    }

    sort(t.begin(), t.end());

    ll ans = 0;
    ll ride = 0;
    ll limit = t[0] + k;

    for (ll i = 0; i < n; i++){
        if (ride < c && t[i] <= limit){
            ride++;
        }
        else{
            ans++;
            ride = 1;
            limit = t[i] + k;

        }
    }
    ans++;

    cout << ans << endl;
}