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

const ll INF=1e9+7;


int main(){
    ll n;
    cin >> n;
    ll a,b;
    cin >> a >> b;
    if(n==1 && a!=b){
        cout << 0 << endl;
        return 0;
    }
    else if(a>b){
        cout << 0 << endl;
        return 0;
    }
    cout << b*(n-1)+a-(a*(n-1)+b)+1 << endl;
    return 0;
}