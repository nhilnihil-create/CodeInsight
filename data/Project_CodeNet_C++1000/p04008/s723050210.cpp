#include "bits/stdc++.h"
#include <fstream>
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

typedef pair<int, int> P;
int N, K;
vector<int> Back[100010];
vector<int> Forward[100010];
int used[3][100010];
vector<int> d[100010];


void bfs(int s) {
    queue<P> que;
    que.push({s, 0});
    while(que.size()) {
        P v = que.front(); que.pop();
        used[0][v.first] = true;
        d[v.second].push_back(v.first);
        for(auto next: Back[v.first]) {
            if (!used[0][next])
                que.push({next, v.second + 1});
        }
    }
}
void dfs2(int s, int depth) {
    //cout << s << " " << depth << endl;
    used[1][s] = true;
    if (depth >= K) return;
    for(auto next: Back[s]) {
        dfs2(next, depth + 1);
    }
}
void dfs(int s, int K){
    used[1][s] = true;
    if (K == 1 && Forward[s][0] != 1) {dfs2(s, K); return;}
    if (K == 0) {dfs2(s, K);return;}
    for(auto next: Forward[s]) {
        if (!used[1][next])
            dfs(next, K - 1);
    }
}


int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    //std::ifstream in("input.txt");
    //std::cin.rdbuf(in.rdbuf());
    cin >> N >> K;
    
    int a[100010];
    rep(i, N) cin >> a[i];
    int ans = 0;
    if (a[0] != 1) ans++;
    a[0] = 1;
    rep(i, N) {
        Forward[i + 1].push_back(a[i]);
        Back[a[i]].push_back(i + 1);
    }
    bfs(1);
    /*
    rep(i, 10) {
        cout << i << ":";
        rep(j, d[i].size()) {
            cout << d[i][j] << " ";
        }
        cout << endl;
    }
    */
    RREP(i, 100000, K + 1) {
        //rep(j, N + 1) cout << used[1][j] <<" ";
        //cout << endl; 
        if (d[i].size()) {
            for(auto v: d[i]) {
                if (!used[1][v]) {
                    //cout << "!" << v << " ";
                    ans++;
                    dfs(v, K);
                }
            }
            //cout << endl;
        }
    }
    cout << ans << endl;


    return 0;
}
