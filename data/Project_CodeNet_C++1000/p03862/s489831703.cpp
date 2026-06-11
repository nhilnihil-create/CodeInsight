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

const ll INF=1e15;

int main()
{
    ll n,x;
    cin >> n >> x;
    vector<ll> a(n);
    rep(i,n){
        cin >> a[i];
    }
    ll ans=0;
    rep(i,n-1){
        if(a[i+1]+a[i]>x){
            ll d=a[i+1]+a[i]-x;
            if(d<=a[i+1]){
                a[i+1]-=d;
            }
            else{
                ll dd=d-a[i+1];
                a[i+1]=0;
                a[i]-=dd;
            }
            ans+=d;
        }
    }
    //cout << setprecision(30);
    cout << ans << endl;
    return 0;
} 
