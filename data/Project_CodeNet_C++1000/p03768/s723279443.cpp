#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define all(a) a.begin(), a.end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;
typedef long long ll;

const int mx = 100000;
vector<int> graph[mx];
int ver[mx], dis[mx], col[mx];
int dp[mx][11];

void splatter(int v, int d, int c){
    if(dp[v][d] != 0)return;
    dp[v][d] = c;
    if(d == 0)return;
    splatter(v, d - 1, c);
    for(int u : graph[v]){
        splatter(u, d - 1, c);
    }
}

int main(){

    int N, M;
    cin >> N >> M;
    rep(i, M){
        int a, b;
        cin >> a >> b;
        a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int Q;
    cin >> Q;
    rep(i, Q){
        cin >> ver[i] >> dis[i] >> col[i];
        ver[i]--;
    }

    for(int i = Q - 1; i >= 0; i--){
        splatter(ver[i], dis[i], col[i]);
    }

    rep(i, N){
        cout << dp[i][0] << endl;
    }
    
}