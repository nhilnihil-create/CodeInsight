#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <iterator>
#include <cassert>
#include <numeric>
#pragma warning(disable:4996) 
 
typedef long long ll;
#define MIN(a, b) ((a)>(b)? (b): (a))
#define MAX(a, b) ((a)<(b)? (b): (a))
#define LINF  9223300000000000000
#define LINF2 1223300000000000000
#define INF 2140000000
const long long MOD = 1000000007;
//const long long MOD = 998244353;

using namespace std;

typedef pair<ll,int> P;
vector<ll> dijkstra(int s, const vector<vector<pair<int,int> > >& G){
    priority_queue< P, vector<P>, greater<P> > que;
    vector<ll> d(G.size(), LINF);
    d[s] = 0;
    que.push(P(0, s));
    while(!que.empty()){
        int curr  = que.top().second;
        ll  dcurr = que.top().first;
        que.pop();
        if(d[curr] < dcurr) continue;
        int i;
        for(i=0; i<(int)G[curr].size(); i++){ 
            int next = G[curr][i].first;
            ll  dist = G[curr][i].second;
            if(d[next] > d[curr] + dist){
                d[next] = d[curr] + dist;
                que.push(P(d[next], next));
            }
        }
    }
    return d;
}

vector<vector<pair<int, int> > > g;

void solve()
{
    int n;
    scanf("%d", &n);
    g.resize(n);
    int i;
    for (i = 0; i < n - 1; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c); a--; b--;
        g[a].push_back(make_pair(b, c));
        g[b].push_back(make_pair(a, c));
    }
    int Q, K;
    scanf("%d%d", &Q, &K); K--;

    vector<ll> dist = dijkstra(K, g);
    for (i = 0; i < Q; i++) {
        int x, y;
        scanf("%d%d", &x, &y); x--; y--;
        ll ans=dist[x] + dist[y];
        printf("%lld\n", ans);
    }

    return;
}

int main(int argc, char* argv[])
{
#if 1
    solve();
#else
    int T;
    scanf("%d%d", &T, &B);
    int t;
    for(t=0; t<T; t++) {
        //printf("Case #%d: ", t+1);
        solve();
    }
#endif
    return 0;
}

