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
//const ll mod = 998244353;

ll lcm(ll a, ll b){
    return a / __gcd(a, b) * b;
}


int main(void)
{
    ll n, k;
    cin >> n >> k;
    map<ll,ll> mp;
    rep(i,n){
        ll a, b;
        cin >> a >> b;
        mp[a] += b;
    }
    for(auto i:mp){
        k -= i.second;
        if(k <= 0){
            cout << i.first << endl;
            return 0;
        }
    }
    return 0;
}
