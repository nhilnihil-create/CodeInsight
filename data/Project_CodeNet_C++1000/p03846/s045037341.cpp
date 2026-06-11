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

int main(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> d(n); //d[i]は、絶対値の差がiであるものの個数
    rep(i,n){
        cin >> a[i];
        d[a[i]]++;
    }
    bool ok=true;
    if(n%2==1){
        for(ll i=0;i<=n-1;i+=2){
            if(i==0){
                if(d[i]!=1){
                    ok=false;
                    break;
                }
            }
            else{
                if(d[i]!=2){
                    ok=false;
                    break;
                }
            }
        }
        if(ok){
            ll ans=1;
            rep(i,n/2){
                ans*=2;
                ans%=mod;
            }
            cout << ans << endl;
        }
        else{
            cout << 0 << endl;
        }
    }
    else{
        for(ll i=1;i<=n-1;i+=2){
            if(d[i]!=2){
                ok=false;
                break;
            }
        }
        if(ok){
            ll ans=1;
            rep(i,n/2){
                ans*=2;
                ans%=mod;
            }
            cout << ans << endl;
        }
        else{
            cout << 0 << endl;
        }
    }
    return 0;
}

