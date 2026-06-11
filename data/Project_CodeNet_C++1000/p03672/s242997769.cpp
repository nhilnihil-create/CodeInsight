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

const ll INF=1e18;

int main(){
    string s;
    cin >> s;
    ll n=s.length();
    ll ans=0;
    for(ll i=1;i<n/2;i++){
        bool ok=true;
        for(ll j=0;j<i;j++){
            if(s[j]!=s[j+i]){
                ok=false;
                break;
            }
        }
        if(ok) ans=i*2;
    }
    cout << ans << endl;
    return 0;
} 