#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)

int dp[30][3001];
int a, b, c, d, e, f;

void dfs(int x, int y){
    int v = x * a + y * b;
    if (100 * v > f) return;

    if(dp[v][0] == 1){
        return;
    }else{
        dp[v][0] = 1;
    }
    
    dfs(x + 1, y);
    dfs(x, y + 1);
}

int main(){
    
    cin >> a >> b >> c >> d >> e >> f;
    rep(i, 30)rep(j, f + 1) dp[i][j] = 0;
    dfs(0, 0);

    for (int i = 0; 100 * i <= f; i++){
        for (int j = 0; j + i <= f; j++){
            if(100 * i + j > f) continue;
            if(e * i >= j && i >= a && dp[i-a][j]){
                dp[i][j] = 1;
                continue;
            }
            if(e * i >= j && i >= b && dp[i-b][j]){
                dp[i][j] = 1;
                continue;
            }
            if(e * i >= j && j >= c && dp[i][j-c]){
                dp[i][j] = 1;
                continue;
            }
            if(e * i >= j && j >= d && dp[i][j-d]){
                dp[i][j] = 1;
                continue;
            }
        }
    }
    
    int mx1 = 0;
    int mx2 = 100 * a;
    rep(i, 30)rep(j, f + 1){
        if(dp[i][j] == 1 && mx1 * (100 * i + j) < mx2 * j){
            mx1 = j;
            mx2 = (100 * i + j);
        }
    }
    cout << mx2 << " " << mx1 << endl;
}