#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define rep(i,n) for(ll i=0;i<(n);i++)
#define pll pair<ll,ll>
#define pii pair<int,int>
#define pq priority_queue
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define endl '\n'
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(c,x) distance(c.begin(),lower_bound(all(c),x))
#define ub(c,x) distance(c.begin(),upper_bound(all(c),x))

using namespace std;

template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}

const ll mod=998244353;

const ll INF=1e9;

int main(){
    ll n;
    cin >> n;
    string s,t;
    cin >> s >> t;
    ll ans=0;
    for(ll i=1;i<=n;i++){
        bool ok=true;
        rep(j,i){
            if(s[n-i+j]!=t[j]) ok=false;
        }
        if(ok) ans=max(ans,i);
    }
    cout << 2*n-ans << endl;
    return 0;
}