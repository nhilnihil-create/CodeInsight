#include <bits/stdc++.h>
using namespace std;

const int RLEN=1<<18|1;
inline char nc() {
    static char ibuf[RLEN],*ib,*ob;
    (ib==ob) && (ob=(ib=ibuf)+fread(ibuf,1,RLEN,stdin));
    return (ib==ob) ? -1 : *ib++;
}
inline int rd() {
    char ch=nc(); int i=0,f=1;
    while(!isdigit(ch)) {if(ch=='-')f=-1; ch=nc();}
    while(isdigit(ch)) {i=(i<<1)+(i<<3)+ch-'0'; ch=nc();}
    return i*f;
}

const int N=1e5+50;
int n,k,mxd[N],del[N],ans;
vector <int> edge[N];
inline void dfs(int x,int f) {
    for(auto v:edge[x]) {
        dfs(v,x);
        if(!del[v]) mxd[x]=max(mxd[x],mxd[v]+1);
    }
    if(mxd[x]==k-1 && f>1) del[x]=1, ++ans;
}
int main() {
    n=rd(), k=rd(), ans+=(rd()!=1);
    for(int i=2;i<=n;i++) edge[rd()].push_back(i);
    dfs(1,0); cout<<ans<<'\n';
}