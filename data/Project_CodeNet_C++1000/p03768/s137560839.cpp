#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;
typedef pair<ll, P> P3;
typedef pair<P ,P> PP;
constexpr ll MOD = ll(1e9) + 7;
constexpr int IINF = INT_MAX;
constexpr ll LLINF = LLONG_MAX;
constexpr int MAX_N = int(1e5) + 5;
constexpr double EPS = 1e-8;
constexpr int di[] = {0, 1, 0, -1}, dj[] = {1, 0, -1, 0};
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define SORT(v) sort((v).begin(), (v).end())
#define SORTR(v) sort((v).rbegin(), (v).rend())
#define ALL(v) (v).begin(), (v).end()

vector<vector<int> > g, dp;

int main() {
    int n, m, q;
    cin >> n >> m;
    g.resize(n);
    dp.resize(n, vector<int>(12,0));
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    cin >> q;
    vector<P3> ls;
    for(int i=0;i<q;i++){
        int v, d, c;
        cin >> v >> d >> c;
        v--;
        ls.push_back({v,{d,c}});
    }
    reverse(ls.begin(), ls.end());
    queue<P> que;
    for(int i=0;i<q;i++){
        int v, d, c;
        v = ls[i].first;
        d = ls[i].second.first;
        c = ls[i].second.second;
        if(dp[v][d] != 0) continue;
        dp[v][d] = c;
        que.push({v,d});
        while(!que.empty()){
            P p = que.front();
            que.pop();
            int now = p.first, r = p.second;
            if(r==0) continue;
            if(dp[now][r-1] == 0){
                dp[now][r-1] = c;
                que.push({now,r-1});
            }
            for(auto nxt : g[now]){
                if(dp[nxt][r-1] == 0){
                    dp[nxt][r-1] = c;
                    que.push({nxt,r-1});
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<=11;j++){
            if(dp[i][j] > 0){
                cout << dp[i][j] << endl;
                break;
            }
            if(j==11){
                cout << 0 << endl;
            }
        }
    }
    return 0;
}
