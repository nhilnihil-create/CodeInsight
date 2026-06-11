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
    ll N,M,R;
    cin >> N >> M >> R;
    vector<ll> r(R);
    rep(i,R){
        cin >> r[i];
        r[i]--;
    }
    sort(r.begin(),r.end());
    vector<vector<ll>> d(N,vector<ll>(N,INF));
    rep(i,M){
        ll a,b,c;
        cin >> a >> b >> c;
        a--;
        b--;
        d[a][b]=c;
        d[b][a]=c;
    }
    rep(k,N){
        rep(i,N){
            rep(j,N){
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
    ll ans=INF;
    do{
        ll sum=0;
        rep(i,R-1){
            sum+=d[r[i]][r[i+1]];
        }
        ans=min(ans,sum);
    }while(next_permutation(r.begin(),r.end()));
    cout << ans << endl;
}