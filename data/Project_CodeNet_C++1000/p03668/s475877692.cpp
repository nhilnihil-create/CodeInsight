#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
using namespace std;
const int M = 1e5 + 10;
vector<int>vc[M];
int dp[M];
int dfs(int u , int pre) {
    int len = vc[u].size();
    for(int i = 0 ; i < len ; i++) {
        int v = vc[u][i];
        if(v == pre) continue;
        dp[u] ^= (dfs(v , u) + 1);
    }
    return dp[u];
}
int main() {
    int n;
    scanf("%d" , &n);
    for(int i = 1 ; i < n ; i++) {
        int u , v;
        scanf("%d%d" , &u , &v);
        vc[u].push_back(v);
        vc[v].push_back(u);
    }
    memset(dp , 0 , sizeof(dp));
    if(dfs(1 , -1)) printf("Alice\n");
    else printf("Bob\n");
    return 0;
}