#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 0x3f3f3f3f
#define N 510
#define pa pair<int,int>
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int n,ans[N*N],id[N*N],cnt[N],num=0;
pa a[N];
int main(){
//  freopen("a.in","r",stdin);
    n=read();for(int i=1;i<=n;++i){
        int x=read();id[x]=i;a[i]=make_pair(x,i);
    }sort(a+1,a+n+1);
    for(int i=1;i<=n;++i){
        int x=a[i].second,pos=a[i].first;ans[pos]=x;cnt[x]=n-x;
        for(int owo=1;owo<x;++owo){
            while(ans[++num]&&num<=pos) continue;
            if(num>pos){puts("No");return 0;}
            ans[num]=x;
        }
    }queue<int>q;
    for(int i=1;i<=n*n;++i){
        if(id[i]&&cnt[id[i]]) q.push(id[i]);
        if(ans[i]) continue;
        if(q.empty()){puts("No");return 0;}int x=q.front();
        ans[i]=x;if(--cnt[x]==0) q.pop();
    }puts("Yes");
    for(int i=1;i<=n*n;++i) printf("%d ",ans[i]);
    return 0;
}
