#include <bits/stdc++.h>
#define FOR(i, begin, end) for(int i=(begin);i<(end);i++)
#define REP(i, n) FOR(i,0,n)
#define IFOR(i, begin, end) for(int i=(end)-1;i>=(begin);i--)
#define IREP(i, n) IFOR(i,0,n)
#define Sort(a) sort(a.begin(), a.end())
#define Reverse(a) reverse(a.begin(), a.end())
#define Lower_bound(v, x) distance(v.begin(), lower_bound(v.begin(), v.end(), x))
#define Upper_bound(v, x) distance(v.begin(), upper_bound(v.begin(), v.end(), x))
#define Max(a, b) a = max(a, b)
#define Min(a, b) a = min(a, b)
#define Ans(f, y, n) if(f) cout << y << endl; else cout << n << endl;
#define int long long
#define INF 1000000000000000000
using namespace std;

using vec = vector<int>;
using mat = vector<vec>;
using Pii = pair<int, int>;
using PiP = pair<int, Pii>;
using PPi = pair<Pii, int>;
using bools = vector<bool>;

template<typename T>
void readv(vector<T> &a){ REP(i, a.size()) cin >> a[i]; }
void readi(vector<int> &a){ REP(i, a.size()){cin >> a[i]; a[i]--;} }
template<typename T>
void debug(vector<vector<T>> m){ REP(i, m.size()){ REP(j, m[i].size()){ cout << m[i][j] << ","; } cout << endl;} }

void dfs(int v, mat &chi, int n, mat &g){
    g[n].push_back(v);
    for(int c: chi[v]) dfs(c, chi, n + 1, g);
}

void dfs2(int v, mat &chi, bools &used, int n){
    used[v] = true;
    if(n == 0) return;
    for(int c: chi[v]) if(!used[c]) dfs2(c, chi, used, n - 1);
}

signed main(){

    int N, K; cin >> N >> K;
    vec a(N); readi(a);
    int ans = 0;
    if(a[0] != 0){
        a[0] = 0;
        ans++;
    }

    mat chi(N), g(N);
    FOR(i, 1, N) chi[a[i]].push_back(i);
    dfs(0, chi, 0, g);

    bools used(N, false);
    IFOR(i, K + 1, N){
        for(int v: g[i]){
            if(used[v]) continue;
            ans++;
            int p = v;
            REP(j, K - 1) p = a[p];
            dfs2(p, chi, used, K - 1);
        }
    }
    cout << ans << endl;
    
    return 0;
}