/*** author: yuji9511 ***/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lpair = pair<ll, ll>;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i=(m);i<(n);i++)
#define rrep(i,m,n) for(ll i=(m);i>=(n);i--)
#define printa(x,n) for(ll i=0;i<n;i++){cout<<(x[i])<<" \n"[i==n-1];};
void print() {}
template <class H,class... T>
void print(H&& h, T&&... t){cout<<h<<" \n"[sizeof...(t)==0];print(forward<T>(t)...);}
vector<ll> tree[100010];
ll v[100010], d[100010], c[100010];
ll a[100010], b[100010];
ll dp[100010][11] = {};

void dfs(ll cur, ll depth, ll color){
    if(dp[cur][depth] != 0) return;
    dp[cur][depth] = color;
    if(depth > 0){
        dfs(cur, depth-1, color);
        for(auto &e: tree[cur]){
            dfs(e, depth-1, color);
        }
    }

}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,M;
    cin >> N >> M;
    rep(i,0,M){
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
        tree[a[i]].push_back(b[i]);
        tree[b[i]].push_back(a[i]);
    }
    ll Q;
    cin >> Q;
    rep(i,0,Q){
        cin >> v[i] >> d[i] >> c[i];
        v[i]--;
    }

    rrep(q,Q-1,0){
        dfs(v[q], d[q], c[q]);
    }
    rep(i,0,N) print(dp[i][0]);

    

}