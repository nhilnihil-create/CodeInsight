/*
    Author:zeke
    
    pass System Test!
    GET AC!!
*/
#include <iostream>
#include <queue>
#include <vector>
#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <algorithm>
#include <functional>
#include <cmath>
#include <queue>
#include <set>
#include <stack>
#include <deque>
#include <map>
#include <iomanip>
#include <utility>
#include <stack>
#include <bitset>
using ll = long long;
using ld = long double;
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define rep3(var, min, max) for (ll(var) = (min); (var) < (max); ++(var))
#define repi3(var, min, max) for (ll(var) = (max)-1; (var) + 1 > (min); --(var))
#define Mp(a, b) make_pair((a), (b))
#define F first
#define S second
#define Icin(s) \
    ll(s);      \
    cin >> (s);
#define Scin(s) \
    ll(s);      \
    cin >> (s);
template <class T>
bool chmax(T &a, const T &b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b)
{
    if (b < a)
    {
        a = b;
        return 1;
    }
    return 0;
}
typedef pair<ll, ll> P;
typedef vector<ll> V;
typedef vector<V> VV;
typedef vector<P> VP;
ll mod = 1e9 + 7;
ll MOD = 1e9 + 7;
ll INF = 1e18;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,w;
    cin>>n>>w;
    VP vec(n);
    ll leastw=1e18;
    rep(i,n){
        cin>>vec[i].F>>vec[i].S;
        chmin(leastw,vec[i].F);
    }
    ll topw=0;
    VV dp(n+1,V(500,0));
    rep(i,n){
        ll disw=vec[i].F-leastw;
        for(int j=i;j>=0;j--){
            rep(k,topw+1){
                chmax(dp[j+1][k+disw],dp[j][k]+vec[i].S);
            }
        }
        topw+=disw;
    }
    ll ans=0;
    rep(i,n+1){
        rep(j,500){
            if(i*leastw+j>w)continue;
            chmax(ans,dp[i][j]);
        }
    }
    cout<<ans<<endl;
}
