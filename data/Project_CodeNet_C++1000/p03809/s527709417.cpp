#include<bits/stdc++.h>
#define reg register
#define maxn 300001
using namespace std;
inline int  read() {
    reg int s = 0, t = 0; reg char ch = getchar();
    while(ch > '9' || ch < '0') t |= ch == '-', ch = getchar();
    while(ch >= '0' && ch <= '9') s = (s << 1) + (s << 3) + (ch ^ 48), ch = getchar();
    return t ? -s : s;
}
bool hh = true;
int nt[maxn], fi[maxn], go[maxn], deg[maxn], f[maxn], a[maxn], cnt, n, root;
void add(int u, int v){
    nt[++cnt] = fi[u]; fi[u] = cnt; go[cnt] = v;
}
void dfs(int u, int fa){
    int sum = 0;
    if(deg[u] == 1) {f[u] = a[u]; return; }
    for(int i = fi[u]; i; i = nt[i]){
        int v = go[i]; if(v == fa) continue;
        dfs(v, u); sum += f[v];
        if(f[v] > a[u]) hh = false;
    }
    f[u] = a[u] * 2 - sum;
    if(f[u] > a[u]) hh = false;
    if(f[u] < 0) hh = false;
}
int main()
{
    n = read();
    for(int i = 1; i <= n; i++) a[i] = read();
    if(n == 2){
        if(a[1] == a[2]) cout << "YES\n";
        else cout << "NO\n";    
        return 0;
    }
    for(int i = 1; i < n; i++){
        int x = read(), y = read();
        add(x, y); add(y, x);
        deg[x]++; deg[y]++;
    }
    for(int i = 1; i <= n; i++) 
    if(deg[i] > 1) root = i;
    dfs(root, 0);
        if(f[root]) {cout <<"NO"<< endl;
        return 0;}
    if(hh) cout << "YES\n";
    else cout << "NO\n";
}