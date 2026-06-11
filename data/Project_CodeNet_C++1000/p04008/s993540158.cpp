#include<bits/stdc++.h>
#define reg register
#define maxn 200001
using namespace std;
inline int  read() {
    reg int s = 0, t = 0; reg char ch = getchar();
    while(ch > '9' || ch < '0') t |= ch == '-', ch = getchar();
    while(ch >= '0' && ch <= '9') s = (s << 1) + (s << 3) + (ch ^ 48), ch = getchar();
    return t ? -s : s;
}
int nt[maxn], fi[maxn], go[maxn], cnt;
int ans, n, k, p[maxn], dp[maxn];
void add(int x, int y){
    nt[++cnt] = fi[x]; fi[x] = cnt; go[cnt] = y;
}
void dfs(int u){
    for(int i = fi[u]; i; i = nt[i]){
        dfs(go[i]);
        if(dp[go[i]] + 1 == k && u != 1) 
        dp[go[i]] = -1, ans++;
        dp[u] = max(dp[u], dp[go[i]] + 1);
       } 
}
int main(){
    n = read(); k = read();
    for(int i = 1; i <= n; i++) {
        int x = read();
        if(i == 1 && x != 1) ans++;
        if(i != 1) add(x, i);
    }
    dfs(1); cout << ans << endl;
}