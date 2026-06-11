#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i,N) for(int i = 0; i < (N); i++)
#define erep(i,N) for(int i = N; i >= 0; i--)
const ll INF = 1000000007;
#define PI 3.1415926535
using Graph = vector<vector<int>>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true;} return false;}
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true;} return false;}
bool seen[100000];
void dfs(const Graph &G, int v) {
    seen[v] = true; // v を訪問済にする
 
    // v から行ける各頂点 next_v について
    for (auto next_v : G[v]) { 
        if (seen[next_v]) continue; // next_v が探索済だったらスルー
        dfs(G, next_v); // 再帰的に探索
    }
}
 
//dpTable
ll dp[55][2];
int main(){
    int N,P;
    cin >> N >> P;
    vector<int> A(N);
    rep(i,N) cin >> A.at(i);
    dp[0][0] = 1;
    for (int i = 1; i <= N; i++) {
        if (A.at(i - 1) % 2 == 0) {
            dp[i][0] = dp[i - 1][0] * 2;
            dp[i][1] = dp[i - 1][1] * 2;
        }
        else {
            dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
            dp[i][1] = dp[i - 1][0] + dp[i - 1][1];
        }
    }
    cout << dp[N][P] << endl;
    return 0;
}