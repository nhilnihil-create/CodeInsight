#pragma region include
#include "bits/stdc++.h"
#define ALL(obj) (obj).begin(),(obj).end()
#define RALL(obj) (obj).rbegin(),(obj).rend()
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define REPR(i, n) for(int i = (int)(n); i >= 0; i--)
#define FOR(i,n,m) for(int i = (int)(n); i < int(m); i++)
#define MOD (int)(1e9+7)
#define INF (int)(1e9)
#define LLINF (int)(4e18)
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
void input() {}
template<typename... R> void input(int& f, R&... r) { scanf("%d", &f); input(r...); }
template<typename... R> void input(double& f, R&... r) { scanf("%lf", &f); input(r...); }
template<typename... R> void input(ll& f, R&... r) { scanf("%lld", &f); input(r...); }
template<typename... R> void input(char& f, R&... r) { scanf("%c", &f); input(r...); }
template<typename... R> void input(string& f, R&... r) { cin >> f; input(r...); }
template<typename T, typename... R> void input(vector<T>& f, R&... r) { REP(i, f.size())input(f[i]); input(r...); }
#pragma endregion

vector<vector<int>> G;
vector<vector<int>> dist;
int N;
// depth : 根からの深さ
void dfs(int v, int n, int p = -1,int depth = 0) {
    dist[n][v] = depth;
    for (int u : G[v]) {
        if (u != p) dfs(u, n, v, depth + 1);
    }
}
    
int main() {
    input(N);
    G.resize(N);
    dist.resize(2, vector<int>(N));
    REP(i, N-1) {
        int a, b; input(a,b);
        a--; b--;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }
    dfs(0,0);
    dfs(N - 1, 1);
    int cnt[2];
    cnt[0] = cnt[1] = 0;
    REP(i, N) {
        if (dist[0][i] <= dist[1][i]) cnt[0]++;
        else cnt[1]++;
    }
    if (cnt[0] > cnt[1]) puts("Fennec");
    else puts("Snuke");
    getchar(); getchar();
}