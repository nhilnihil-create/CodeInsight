#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)

struct edge{int to, cost;};

int per[8];
int dp[201][200][200];
int n, m, R;
int r[8];


int func(){
    int res = 0;
    for (int i = 0; i < R - 1; i++){
        res += dp[n][r[per[i]]][r[per[i+1]]];
    }
    return res;
}



int main(){
    int const INF = 1000000000;
    
    cin >> n >> m >> R;
    rep(i, R) {cin >> r[i]; r[i]--;}
    int a, b, c;
    
    rep(i, n)rep(j, n) dp[0][i][j] = INF;
    rep(i, n) dp[0][i][i] = 0;
    rep(i, m){
        cin >> a >> b >> c;
        a--; b--;
        dp[0][a][b] = c;
        dp[0][b][a] = c;
    }

    rep(k, n)rep(i, n)rep(j, n){
        dp[k+1][i][j] = min(dp[k][i][j], dp[k][i][k] + dp[k][k][j]);
    }
    
    int ans = INF;
    rep(i, R) per[i] = i;
    do{
        ans = min(ans, func());
    }while(next_permutation(per, per + R));

    cout << ans << endl;
}