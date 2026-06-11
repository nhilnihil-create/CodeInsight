#include "bits/stdc++.h"
using namespace std;
const int maxn = 123567;
vector<int> g[maxn];
int dfs(int cur, int pr){
    int ans = 0;
    for(int v : g[cur])
        if(v != pr)
            ans ^= dfs(v, cur) + 1;
    return ans;
}
int main(){
    int n;
    scanf("%d", &n);
    for(int e = 0; e < n - 1; e ++){
        int x, y; scanf("%d %d", &x, &y); x--; y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    if(dfs(0, -1)) printf("Alice\n");
    else printf("Bob\n");
    return 0;
}
