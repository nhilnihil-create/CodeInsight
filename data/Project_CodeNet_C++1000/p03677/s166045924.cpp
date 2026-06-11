#include<bits/stdc++.h>
#define me(a,x) memset(a,x,sizeof a)
#define cp(a,x) memcpy(a,x,sizeof a)
using namespace std;
typedef long long LL;
const int N=1e5+2;
char B[1<<14],*S=B,*T=B;
#define gc (S==T&&(T=(S=B)+fread(B,1,1<<14,stdin),S==T)?-1:*S++)
inline int read(){
    int x=0,f=1; char ch=gc;
    while(ch<'0' || ch>'9'){if(ch=='-')f=-1; ch=gc;}
    while(ch>='0' && ch<='9'){x=(x<<1)+(x<<3)+ch-'0'; ch=gc;}
    return x*f;
}
struct P{int x,y;}q[N];
int Cmp(P x,P y){return x.x<y.x;}
int a[N]; LL c[N];
int main(){
    int i,n=read(),m=read();
    for(i=1;i<=n;++i) a[i]=q[i].x=read(),q[i].y=i;
    sort(q+1,q+1+n,Cmp);
    LL s=0,mx=0,u=0; int p;
    for(i=2;i<=n;++i){
        if(a[i]>a[i-1]);
        else s+=m-a[i-1],++u;
    }
    q[0].x=0;
    for(i=1;i<=n;++i){
        int x=q[i].y,o=q[i].x;
        s+=(LL)(o-q[i-1].x)*u;
        if(o!=q[i-1].x){
            if(s>mx)mx=s,p=o;
        }
        if(x<n && a[x]<a[x+1]) ++u;
        if(x>1 && a[x-1]<a[x]) --u,s-=a[x]-a[x-1];
        if(x<n && a[x]>a[x+1]) ++u;
        if(x>1 && a[x-1]>a[x]) --u,s-=(m-a[x-1]+a[x]);
    }
    LL ans=0;
    for(i=1;i<n;++i){
        if(a[i]<a[i+1]){
            if(a[i]<p && p<=a[i+1])ans+=1+a[i+1]-p;
            else ans+=a[i+1]-a[i];
        }
        else if(a[i]>a[i+1]){
            if(p>a[i]) ans+=1+m-p+a[i+1];
            else if(p<=a[i+1]) ans+=1+a[i+1]-p;
            else ans+=m-a[i]+a[i+1];
        }
    }
    printf("%lld\n",ans);
    return 0;
}