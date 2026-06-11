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
const ll mod=1e9+7;

int main(){
    ll n,k;
    cin >> n >> k;
    vector<ll> a(n),b(n);
    rep(i,n){
        cin >> a[i] >> b[i];
    }
    ll ans=0;
    rep(i,n){
        bool ok=true;
        rep(j,30){
            if((k>>j)%2==0 && (a[i]>>j)%2==1){
                ok=false;
                break;
            }
        }
        if(ok){
            ans+=b[i];
        }
    }
    rep(i,30){
        if((k>>i)%2==1){
            ll sum=0;
            ll v=k;
            v&=~(1<<i);
            for(ll j=i-1;j>=0;j--){
                if((v>>j)%2==0){
                    v|=(1<<j);
                }
            }
            rep(j,n){
                bool ok=true;
                rep(p,30){
                    if((v>>p)%2==0 && (a[j]>>p)%2==1){
                        ok=false;
                        break;
                    }
                }
                if(ok){
                    sum+=b[j];
                }
            }
            ans=max(ans,sum);
            //cout << i << " " << v << " " << sum << endl;
        }
    }
    cout << ans << endl;
    return 0;
}