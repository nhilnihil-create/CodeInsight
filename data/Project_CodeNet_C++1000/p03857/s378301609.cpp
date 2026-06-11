#include "bits/stdc++.h"
 
typedef long long ll;
// #define int ll
#define fi first
#define se second
#define SORT(a) sort(a.begin(),a.end())
#define rep(i,n) for(int i = 0;i < (n) ; i++) 
#define REP(i,n) for(int i = 0;i < (n) ; i++) 
#define MP(a,b) make_pair(a,b)
#define pb(a) push_back(a)
// #define INF LLONG_MAX/2

using namespace std;

int MOD = 1000000007;
int n,k,l;

int par[200010];
int rnk[200010];
void init(int n){
    for(int i=0;i<n;i++){
        par[i] = i;
        rnk[i] = 0;
    }
}
int find(int x){
    if(par[x] == x) return x;
    else return par[x] = find(par[x]);
}
void unite(int x,int y){
    x = find(x);
    y = find(y);
    if(x == y) return;

    if(rnk[x] < rnk[y]) par[x] = y;
    else{
        par[y] = x;
        if(rnk[x] == rnk[y]) rnk[x]++;
    }
}
bool same(int x,int y){
    return find(x) == find(y);
}

signed main(){

    cin >> n >> k >> l;
    int p[200010];
    int q[200010];
    int r[200010];
    int s[200010];
    rep(i,k) cin >> p[i] >> q[i];
    rep(i,l) cin >> r[i] >> s[i];

    int oya[200010][2];
    init(n+1);
    rep(i,k) unite(p[i],q[i]);
    for(int i = 1; i<=n;i++) oya[i][0] = find(i);

    init(n+1);
    rep(i,l) unite(r[i],s[i]);
    for(int i = 1; i<=n;i++) oya[i][1] = find(i);

    map<pair<int,int>,int> mp;

    for(int i = 1; i<=n;i++){
        mp[MP(oya[i][0],oya[i][1])]++;
    }

    for(int i = 1; i<=n;i++) cout << mp[MP(oya[i][0],oya[i][1])] << " " ;
    cout << endl;
    // rep(i,n) cerr << oya[i+1][0] << " " << oya[i+1][1] << endl;

    

    return 0;
}
// g++ -std=c++14 code1.cpp
// rm -r -f test;oj dl 