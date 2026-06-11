#include "bits/stdc++.h"
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <map>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>
#include <set>
#include <tuple>
using namespace std;

#define FOR(i,init,a) for(int i=init; i<a; i++)
#define rep(i,a) FOR(i,0,a)
#define rrep(i,a) for(int i=a; i>=0; i--)
#define rep1(i,a) for(int i=1; i<=a; i++)
#define cout1(a) cout << a << endl;
#define cout2(a,b) cout << a << " " << b << endl;
#define cout3(a,b,c) cout << a << " " << b << " " << c << endl;
#define cout4(a,b,c,d) cout << a << " " << b << " " << c << " " << d << endl;
#define mem(a,n) memset( a, n, sizeof(a))
#define all(a) a.begin(),a.end()
#define chmin(a,b) a=min(a,b);
#define chmax(a,b) a=max(a,b);

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> V;
typedef vector<V> VV;
typedef vector<VV> VVV;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LLINF = 1e18;
static const double pi = 3.141592653589793;

int N,M,Q;
int col[100009],v[100009],d[100009],c[100009];
int vis[100009];
vector<int> G[100009];

void dfs(int cur,int dist,int co){
    if(vis[cur]>=dist) return;
    vis[cur]=dist;
    if(col[cur]==0) col[cur]=co;
    if(dist){
        for(auto &v:G[cur]){
            dfs(v,dist-1,co);
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>N>>M;
    rep(i,M){
        int a,b; cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    
    cin>>Q;
    rep(i,Q) cin>>v[i]>>d[i]>>c[i];
    
    mem(vis,-1);
    rrep(i,Q-1){
        dfs(v[i],d[i],c[i]);
    }
    
    rep1(i,N) cout1(col[i])
}