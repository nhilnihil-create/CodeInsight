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
vector<int> E[N];
int n;
int dfs(int u,int fa) {
    int ret=0;
    for(int v:E[u])
        if(v!=fa) ret^=(dfs(v,u)+1);
    return ret;
}
int main() {
    cin>>n;
    for(int i=1,u,v;i<n;i++) u=gi(),v=gi(),E[u].push_back(v),E[v].push_back(u);
    dfs(1,0)?puts("Alice"):puts("Bob");
    return 0;
}
