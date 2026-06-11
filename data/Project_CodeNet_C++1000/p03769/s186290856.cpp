#include<cstdio>
#include<algorithm>
#define rep(i,a,b) for(register int i=a;i<=b;++i)
using namespace std;
typedef long long ll;
ll s;
int a[210],b[50+5],c[210];
int i,j,k,l,t,n,m,mx,tot,top,now;
int main(){
    scanf("%lld",&s);
    mx=50;
    while((1ll<<mx)>s)--mx;
    s-=(1ll<<mx),m=mx,tot=2*m,now=m;
    c[++top]=++now,c[++top]=now,tot+=2;
    while(s){
        while((1ll<<mx)>s)--mx;
        s-=(1ll<<mx),b[mx]=++now,c[++top]=now,tot+=2;
    }
    printf("%d\n",tot);
    rep(i,0,m){
        if(i)printf("%d ",i);
        if(b[i])printf("%d ",b[i]);
    }
    rep(i,1,m)printf("%d ",i);
    rep(i,1,top)printf("%d ",c[i]);
    return 0;
}