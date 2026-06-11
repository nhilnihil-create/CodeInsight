#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define REP(i,x,n) for(int i = (x); i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1);

int main(void)
{
    ll n;
    cin >> n;
    map<ll,ll> mp;
    rep(i,n){
        ll a;
        cin >> a;
        mp[a]++;
    }
    ll w=0, h=0;
    for(auto x:mp){
        if(x.second >= 2){
            w = max(w, x.first);
        }
    }
    mp[w] -= 2;
    for(auto x:mp){
        if(x.second >= 2){
            h = max(h, x.first);
        }
    }
    cout << w*h << endl;
    return 0;
}
