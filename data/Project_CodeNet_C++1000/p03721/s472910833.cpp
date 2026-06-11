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

    ll n,k;
    cin >> n >> k;
    vector<pair<ll,ll>> p(n);
    for (ll i = 0;i < n;i++){
        cin >> p[i].first >> p[i].second;
    }

    sort(p.begin(), p.end());

    ll now = 0;
    ll ans = 0;

    for (ll i = 0; i < n; i++){
        now += p[i].second;
        if (now >= k){
            ans = p[i].first;
            break;
        }
    }

    cout << ans << endl;
}