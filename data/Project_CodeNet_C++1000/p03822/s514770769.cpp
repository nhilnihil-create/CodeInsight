#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int gi() {
    int x=0,o=1;char ch=getchar();
    while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
    if(ch=='-') o=-1,ch=getchar();
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*o;
}
int n,st[N],f[N];
vector<int> E[N];
void dfs(int u) {
    if(E[u].empty()) return;
    for(int v:E[u]) dfs(v);
    int top=0;
    for(int v:E[u]) st[++top]=f[v];
    sort(st+1,st+top+1,greater<int>());
    for(int i=1;i<=top;i++) f[u]=max(f[u],st[i]+i);
}
int main() {
    cin>>n;
    for(int i=2;i<=n;i++) E[gi()].push_back(i);
    dfs(1);printf("%d\n",f[1]);
    return 0;
}
//orzgzy
//鸡贼明年进队超稳
