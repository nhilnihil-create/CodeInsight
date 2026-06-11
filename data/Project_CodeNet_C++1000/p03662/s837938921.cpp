#include "bits/stdc++.h"
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define rrep(i,n) for( int i = n; i >= 0; i-- )
#define REP(i,s,t) for( int i = s; i <= t; i++ )
#define RREP(i,s,t) for( int i = s; i >= t; i-- )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 1000000000000000000

vector<int> G[100010];
int dA[100010];
int dB[100010];
void dfs(int v, int parent, int depth, int turn) {
    if (turn == 0)
        dA[v] = depth;
    else
        dB[v] = depth;
    for(auto to: G[v]) {
        if (to == parent) continue;
        dfs(to, v, depth + 1, turn);
    }
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    rep(i, N - 1) {
        int s, t;
        cin >> s >> t;
        s--; t--;
        G[s].push_back(t);
        G[t].push_back(s);
    }
    dfs(0, -1, 0, 0);
    dfs(N - 1, -1, 0, 1);
    int A = 0, B = 0;
    rep(i, N) {
        if (dA[i] <= dB[i]) A++;
        else B++;
    }
    if (A > B) {
        cout << "Fennec" << endl;
    } else {
        cout << "Snuke" << endl;
    }

    return 0;
}
