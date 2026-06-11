#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;
const int MOD2 = 998244353;


int cost[305][305];
int nxt[305][305];
int path[305][305];

int n, m;
void warshall_floyd(){
    rep(k, n){
        rep(i, n){
            rep(j, n) {
                if (cost[i][j] > cost[i][k] + cost[k][j]){
                    cost[i][j] = cost[i][k] + cost[k][j];
                    nxt[i][j] = nxt[i][k];
                }
            }
        }
    }
}

int sta[305], sp;


void checkShortestPath(int start, int goal) {
    vector<int> v;
    for (int cur = start; cur != goal; cur = nxt[cur][goal])
        v.push_back(cur);
    v.push_back(goal);
    rep(i, v.size()-1) path[v[i]][v[i+1]] = 0, path[v[i+1]][v[i]] = 0;
}

int main(){
    cin >> n >> m;

    rep(i, 305) rep(j, 305) if (i != j) cost[i][j] = INF;
    rep(i, 305) rep(j, 305) nxt[i][j] = j;

    rep(i, m){
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        cost[a][b] = c;
        cost[b][a] = c;
        path[a][b] = 1;
        path[b][a] = 1;
    }

    warshall_floyd();

    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if (i != j) checkShortestPath(i, j);
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if (i != j && path[i][j] == 1) ans++;
        }
    }

    cout << ans / 2 << endl;

    return 0;
}
