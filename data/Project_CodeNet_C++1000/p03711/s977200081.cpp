#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define rep(i,n) for(ll i=0;i<(n);i++)
#define pll pair<ll,ll>
#define pq priority_queue
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(c,x) distance(c.begin(),lower_bound(all(c),x))
#define ub(c,x) distance(c.begin(),upper_bound(all(c),x))

using namespace std;

template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}

const ll mod=1e9+7;

const ll INF=1e10+100;

int main()
{
    ll x,y;
    cin >> x >> y;
    ll a[7]={1,3,5,7,8,10,12};
    ll b[4]={4,6,9,11};
    bool ok1=false,ok2=false,ok3=false,ok4=false;
    rep(i,7){
        if(a[i]==x) ok1=true;
        if(a[i]==y) ok2=true;
    }
    rep(i,4){
        if(b[i]==x) ok3=true;
        if(b[i]==y) ok4=true;
    }
    if((ok1 && ok2) || (ok3 && ok4)) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
} 