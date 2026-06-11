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
    ll n,W;
    cin >> n >> W;
    vector<ll> v(n),w(n);
    vector<vector<ll>> x(4);
    ll c=-1;
    rep(i,n){
        cin >> w[i] >> v[i];
        if(i==0) c=w[i];
        w[i]-=c;
        x[w[i]].push_back(v[i]);
    }
    ll ans=-1;
    vector<vector<ll>> y(4);
    rep(i,4){
        sort(x[i].rbegin(),x[i].rend());
        y[i].push_back(0LL);
        rep(j,x[i].size()){
            y[i].push_back(y[i][j]+x[i][j]);
            //cout << y[i][j+1] << endl;
        }
    }
    rep(i,y[0].size()){
        rep(j,y[1].size()){
            rep(k,y[2].size()){
                rep(l,y[3].size()){
                    //cout << i << " " << j << " " << k << " " << l << endl;
                    if(j+2*k+3*l+(i+j+k+l)*c<=W){
                        ans=max(ans,y[0][i]+y[1][j]+y[2][k]+y[3][l]);
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}