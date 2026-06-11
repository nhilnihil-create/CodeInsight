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

const ll INF=1e9+7;

ll dp[50][500][500];

int main(){
    ll n,ma,mb;
    cin >> n >> ma >> mb;
    vector<ll> a(n),b(n),c(n);
    rep(i,50){
        rep(j,500){
            rep(k,500){
                dp[i][j][k]=INF;
            }
        }
    }
    rep(i,n){
        cin >> a[i] >> b[i] >> c[i];
    }
    dp[0][0][0]=0;
    rep(i,n){
        rep(j,500){
            rep(k,500){
                dp[i+1][j][k]=min(dp[i+1][j][k],dp[i][j][k]);
                if(j-a[i]>=0 && k-b[i]>=0){
                    dp[i+1][j][k]=min(dp[i+1][j][k],dp[i][j-a[i]][k-b[i]]+c[i]);
                }
            }
        }
    }
    ll ans=INF;
    for(ll i=1;i<500;i++){
        for(ll j=1;j<500;j++){
            if(dp[n][i][j]==INF) continue;
            ll d=gcd(i,j);
            ll p=i/d;
            ll q=j/d;
            if(p==ma && q==mb){
                ans=min(ans,dp[n][i][j]);
            }
        }
    }
    if(ans==INF) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}