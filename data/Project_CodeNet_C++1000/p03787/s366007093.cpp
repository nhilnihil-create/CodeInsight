//marico el que lo lea
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <stdlib.h>
#include <assert.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> ii;

void fastIO() {
	std::ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}

#define FOR(i,f,t) for(int i=f; i<(int)t; i++)
#define FORR(i,f,t) for(int i=f; i>(int)t; i--)
#define FORE(i,c) for(auto i = (c).begin(); i != (c).end(); i++)
#define pb push_back
#define all(obj) obj.begin(), obj.end()
#define ms(obj, val) memset(obj, val, sizeof(obj))
#define ms2(obj, val, sz) memset(obj, val, sizeof(obj[0])*sz)

#define fst first
#define snd second

template<typename T, typename U> inline void mnze(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void mxze(T &x, U y) { if(x < y) x = y; }

void _scan( int &x ) { scanf("%d",&x); }
void _scan( long long &x ) { scanf("%lld",&x); }
void _scan( double &x ) { scanf("%lf",&x); }
void _scan( char &x ) { scanf(" %c",&x); }
void _scan( char *x ) { scanf("%s",x); }
void scan() {}
template<typename T, typename... U>
void scan( T& head, U&... tail ) { _scan(head); scan(tail...);}

template<typename T> void _dbg(const char* sdbg, T h) { cerr<<sdbg<<"="<<h<<"\n"; }
template<typename T, typename... U> void _dbg(const char* sdbg, T h, U... t) {
	while(*sdbg != ',')cerr<<*sdbg++; cerr<<"="<<h<<","; _dbg(sdbg+1, t...);
}

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#define debugv(x) {{cerr <<#x <<" = "; FORE(_i, (x)) cerr <<*_i <<", "; cerr <<"\n"; }}
#define debuga(x, sz) {{cerr <<#x <<" = "; FOR(_i, 0, sz) cerr << x[_i] <<", "; cerr <<"\n"; }}
#else
#define debug(...) (__VA_ARGS__)
#define debugv(x)
#define debuga(x, sz)
#define cerr if(0)cout
#endif

///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

const int MAXN = 1e5+5;
ll N, M;
vi G[MAXN];
int vis[MAXN], s;
bool bip;
void dfs(int v, int col=1){
    s++;
    vis[v]=col;
    for(int u:G[v]){
        if(vis[u]==-1) dfs(u,1-col);
        else if(vis[u]==col) bip = false;
    }
}

int main(){
    scan(N, M);
    FOR(i,0,M){
        int v,u; scan(v,u); v--; u--;
        G[v].pb(u);
        G[u].pb(v);
    }
    ms(vis,-1);
    ll ans = 0, cnt1=0, cnt2=0, cnt3=0;
    FOR(v,0,N){
        if(vis[v]==-1){
            s = 0;
            bip = true;
            dfs(v);
            if(s==1){
                ans += 2*N - 1 - cnt3*2;
                cnt3++;
            }else{
                ans += bip+1;
                if(bip){
                    ans += cnt1*2 + cnt2*4;
                    cnt2++;
                }else{
                    ans += (cnt1+cnt2)*2;
                    cnt1++;
                }
            }
        }
    }
    printf("%lld\n",ans);
}
