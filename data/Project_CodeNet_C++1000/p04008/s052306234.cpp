//2018.9.29 by ljz
#include<bits/stdc++.h>
using namespace std;
#define res register int
#define LL long long
#define inf 0x3f3f3f3f
#define eps 1e-15
inline int read(){
    res s=0;
    bool w=0;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')w=1;ch=getchar();}
    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=getchar();
    return w?-s:s;
}
inline void _swap(res &x,res &y){
    x^=y^=x^=y;
}
inline int _abs(const res &x){
    return x>0?x:-x;
}
inline int _max(const res &x,const res &y){
    return x>y?x:y;
}
inline int _min(const res &x,const res &y){
    return x<y?x:y;
}
const int N=1e5+10;
namespace MAIN{
    int n,k;
    int fa[N];
    struct E{
        int next,to;
        E() {}
        E(res next,res to):next(next),to(to) {}
    }edge[N];
    int head[N],cnt;
    inline void addedge(const res &u,const res &v){
        edge[++cnt]=E(head[u],v),head[u]=cnt;
    }
    int ans;
    int dfs(const res &x,const res &depx){
        res ret=depx;
        for(res i=head[x];~i;i=edge[i].next){
            res tox=edge[i].to;
            ret=_max(ret,dfs(tox,depx+1));
        }
        if(fa[x]!=1&&ret-depx==k-1){ans++;return 0;}
        return ret;
    }
    inline void MAIN(){
        memset(head,-1,sizeof(head));
        n=read(),k=read();
        for(res i=1;i<=n;i++)fa[i]=read();
        for(res i=2;i<=n;i++)addedge(fa[i],i);
        if(fa[1]!=1)ans++;
        fa[1]=1;
        dfs(1,0);
        printf("%d\n",ans);
    }
}
int main(){
    MAIN::MAIN();
    return 0;
}