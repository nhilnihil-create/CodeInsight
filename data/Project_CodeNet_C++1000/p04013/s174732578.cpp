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

ll dp[55][55][3000];

int main()
{
    ll n,a;
    cin >> n >> a;
    vector<ll> x(n);
    rep(i,n){
        cin >> x[i];
    }
    dp[0][0][0]=1;
    rep(i,n){
        rep(k,n){
            rep(j,3000){
                if(x[i]+j<3000){
                    dp[i+1][k+1][x[i]+j]+=dp[i][k][j];
                }
                dp[i+1][k][j]+=dp[i][k][j];
            }
        }
    }
    ll ans=0;
    rep(i,n){
        ans+=dp[n][i+1][(i+1)*a];
    }
    cout << ans << endl;
    return 0;
} 
