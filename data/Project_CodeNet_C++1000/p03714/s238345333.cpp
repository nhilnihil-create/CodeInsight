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
    ll n;
    cin >> n;
    vector<ll> a(3*n),r(n+1),l(n+1);
    priority_queue<ll> p2;
    priority_queue<ll,vector<ll>,greater<ll>> p1;
    rep(i,3*n){
        cin >> a[i];
    }
    rep(i,n){
        p1.push(a[i]);
        l[0]+=a[i];
    }
    rep(i,n){
        p1.push(a[n+i]);
        ll be=p1.top();
        p1.pop();
        l[i+1]=l[i]+a[n+i]-be;
        //cout << l[i+1] << endl;
    }
    rep(i,n){
        
        p2.push(a[3*n-1-i]);
        r[0]+=a[3*n-1-i];
    }
    rep(i,n){
        p2.push(a[2*n-1-i]);
        ll be=p2.top();
        p2.pop();
        r[i+1]=r[i]+a[2*n-1-i]-be;
        //cout << r[i+1] << endl;
    }
    ll ans=-INF;
    rep(i,n+1){
        ans=max(ans,l[i]-r[n-i]);
        //cout << ans << endl;
    }
    cout << ans << endl;
}
