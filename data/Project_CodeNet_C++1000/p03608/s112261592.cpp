#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(x) (x).begin(),(x).end() //sortなどの引数を省略したい
#define SIZE(x) ((ll)(x).size()) //sizeをsize_tからllに直しておく
#define MAX(x) *max_element(ALL(x)) //最大値を求める
#define MIN(x) *min_element(ALL(x)) //最小値を求める
typedef long long ll;
typedef long double ld;

int main(){
    ll n,m,r; cin>>n>>m>>r;
    vector<ll> v(r);
    REP(i,r)cin>>v[i], v[i]--;
    vector<vector<ll>> g(n,vector<ll> (n, 10000000));
    REP(i,n)g[i][i]=0;
    REP(i,m){
        ll a,b,c; cin>>a>>b>>c;
        a--; b--;
        g[a][b]=c;
        g[b][a]=c;
    }
    REP(k,n)REP(i,n)REP(j,n){
        g[i][j]=min(g[i][j], g[i][k]+g[k][j]);
    }
    ll ans=1e16;
    sort(ALL(v));
    do {
        ll preans=0;
        FOR(i,1,r){
            preans+=g[v[i-1]][v[i]];
        }
        ans=min(preans, ans);
    }while(next_permutation(ALL(v)));
    cout<< ans <<endl;
    return 0;
}
