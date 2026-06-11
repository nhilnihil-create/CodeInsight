#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <list>
#include <stack>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
#define mkp make_pair
#define fi first
#define se second
#define pt(num) cout << num << "\n"
#define moC(a, s, b) (a)=((a)s(b)+MOD)%MOD
#define max(a, b) ((a)>(b) ? (a):(b))
#define min(a, b) ((a)<(b) ? (a):(b))
#define chmax(a, b) (a<b ? a=b : 0)
#define chmin(a, b) (a>b ? a=b : 0)
#define INF 1000000000000000000
#define MOD 1000000007LL
#define MAX 101010
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef map<ll, ll> Map;

vector<ll> g[MAX];
ll N, M;
ll Q;
ll v[MAX], d[MAX], c[MAX];
ll dp[MAX][11], clr[MAX];


void coloring(ll v, ll d, ll c) {
    if(dp[v][d]==1) return;
    dp[v][d]=1;
    if(d==0) {
        clr[v]=c;
        return;
    }
    
    coloring(v, d-1, c);
    for(auto u: g[v])
        coloring(u, d-1, c);
}

int main(void) {
    cin >> N >> M;
    ll i;
    
    for(i=0; i<M; i++) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    cin >> Q;
    for(i=0; i<Q; i++) {
        cin >> v[i] >> d[i] >> c[i];
        v[i]--;
    }
    
    for(i=Q-1; i>=0; i--)
        coloring(v[i], d[i], c[i]);
    
    for(i=0; i<N; i++)
        pt(clr[i]);
}

