#include<bits/stdc++.h>
#define reg register
#define maxn 1000001
using namespace std;
inline int  read() {
    reg int s = 0, t = 0; reg char ch = getchar();
    while(ch > '9' || ch < '0') t |= ch == '-', ch = getchar();
    while(ch >= '0' && ch <= '9') s = (s << 1) + (s << 3) + (ch ^ 48), ch = getchar();
    return t ? -s : s;
}
int nt[maxn], go[maxn], fi[maxn], n, cnt, sg[maxn];
void add(int x, int y){
    nt[++cnt] = fi[x]; fi[x] = cnt; go[cnt] = y;
}
void dfs(int x, int fa){
    for(int i = fi[x]; i; i = nt[i]){
        int v = go[i]; if(v == fa) continue;
        dfs(v, x); sg[x] ^= (sg[v] + 1);
    }
}
int main(){
    n = read();
    for(int i = 1; i < n; i++){
        int x = read(), y = read();
        add(x, y); add(y, x);
    }
    dfs(1, 0);
    if(sg[1] == 0) printf("Bob\n");
    else printf("Alice\n");
}