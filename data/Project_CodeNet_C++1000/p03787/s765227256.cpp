/*****************************************************/
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <cmath>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

#define   offcin        ios::sync_with_stdio(false)
#define   DEBUG         freopen("#.txt", "r", stdin)
#define   sigma_size    26
#define   lson          l,m,v<<1
#define   rson          m+1,r,v<<1|1
#define   slch          v<<1
#define   srch          v<<1|1
#define   ll            long long
#define   ull           unsigned long long
#define   lowbit(x)     (x&-x)

const int    INF    = 0x3f3f3f3f;
const ll     INFF   = 1e18;
const double pi     = acos(-1.0);
const double inf    = 1e18;
const double eps    = 1e-9;
const ll     mod    = 1e9+7;
const int    maxmat = 10;
const ull    BASE   = 133333331;

/*****************************************************/
inline void RI(int &x) {
      char c;
      while((c=getchar())<'0' || c>'9');
      x=c-'0';
      while((c=getchar())>='0' && c<='9') x=(x<<3)+(x<<1)+c-'0';
}
inline ll bits(ll x) {
      return !x ? x : bits(x - lowbit(x)) + 1;
}
/*****************************************************/

const int maxn = 1e5 + 5;

std::vector<int> G[maxn];
int c[maxn];
bool used[maxn];
int N, M;

bool bipartitite(int u) {
    bool ok = true;
    for (int v : G[u]) {
        if (c[u] == c[v]) ok = false;
        if (!c[v]) {
            c[v] = 3 - c[u];
            if (!bipartitite(v)) ok = false;
        }
    }
    return ok;
}

int main(int argc, char const *argv[]) {
    cin>>N>>M;

    memset(c, 0, sizeof(c));
    memset(used, false, sizeof(used));
    for (int i = 0; i < M; i ++) {
        int u, v;
        scanf("%d%d", &u, &v);
        used[u] = used[v] = true;
        G[u].push_back(v);
        G[v].push_back(u);
    }


    int I = 0, B = 0, P = 0;

    for (int i = 1; i <= N; i ++) {
        if (!used[i]) I ++;
        else if (!c[i]) {
            c[i] = 1;
            if (bipartitite(i)) B ++;
            else P ++;
        }
    }

    long long ans = 0;
    ans += (ll)I * I + 2ll * I * (N - I);
    ans += (ll)P * P + 2ll * P * B + 2ll * B * B;

    cout<<ans<<endl;
    return 0;
}