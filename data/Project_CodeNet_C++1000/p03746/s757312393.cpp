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

int N,M;
int dv[100009];
bool vis[100009];
vector<int> G[100009], ans;

void dfs(int cur){
    vis[cur]=1;
    ans.push_back(cur);
    bool f=true;
    for(auto &v:G[cur]){
        if(!vis[v]){
            f=false;
            dfs(v);
            break;
        }
    }
    if(f) return;
}

void pr(){
    cout1(ans.size())
    rep(i,ans.size()){
        if(i) cout<<" ";
        cout<<ans[i];
    }
    cout<<endl;
    exit(0);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>N>>M;
    rep(i,M){
        int a,b; cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
        dv[a]++;
        dv[b]++;
    }
    
    rep1(i,N){
        if(dv[i]==1){
            dfs(i);
            pr();
        }
    }
    
    dfs(1);
    reverse(all(ans));
    for(auto &v:G[1]){
        if(!vis[v]){
            dfs(v);
            break;
        }
    }
    pr();
}