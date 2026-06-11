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
    string s;
    cin >> s;
    ll n=s.length();
    bool N=false;
    bool W=false;
    bool S=false;
    bool E=false;
    rep(i,n){
        if(s[i]=='N') N=true;
        if(s[i]=='W') W=true;
        if(s[i]=='S') S=true;
        if(s[i]=='E') E=true;
    }
    bool x=(N==S);
    bool y=(W==E);
    if(x&y) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}