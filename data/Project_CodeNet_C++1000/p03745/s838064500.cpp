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
    vector<ll> a(n);
    rep(i,n){
        cin >> a[i];
    }
    ll st=a[0];
    bool up=false,dw=false,neu=true;
    ll ans=1;
    rep(i,n){
        if(i==0) continue;
        if(neu){
            if(a[i]>a[i-1]){
                neu=false;
                up=true;
            }
            else if(a[i]<a[i-1]){
                neu=false;
                dw=true;
            }
        }
        else if(dw){
            if(a[i]>a[i-1]){
                dw=false;
                neu=true;
                ans++;
            }
        }
        else if(up){
            if(a[i]<a[i-1]){
                up=false;
                neu=true;
                ans++;
            }
        }
    }
    cout << ans <<endl;
    return 0;
}