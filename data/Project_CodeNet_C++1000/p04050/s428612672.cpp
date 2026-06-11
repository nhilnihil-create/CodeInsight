#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define per(i,r,l) for(int i=(r);i>=(l);--i)
using namespace std;
const int maxn=200010;
int n,m,a[maxn],b[maxn],cnt,t;
int main(){
    scanf("%d%d",&n,&m);
    rep(i,1,m) scanf("%d",&a[i]),t+=a[i]&1;
    if(t>=3) return puts("Impossible"),0;
    if(t==0){
        rep(i,1,m) printf("%d ",a[i]);puts("");
        b[cnt=1]=1;
        rep(i,1,m-1) b[++cnt]=a[i];t=a[m]-1;
        rep(i,1,t/4) b[++cnt]=2;b[++cnt]=1;t=t-(t/4)*2-1;
        rep(i,1,t/2) b[++cnt]=2;
        printf("%d\n",cnt);
        rep(i,1,cnt) printf("%d ",b[i]);
        return 0;
    }
    if(t==1){
        rep(i,1,m) if(a[i]&1){swap(a[m],a[i]);break;}
        rep(i,1,m) printf("%d ",a[i]);puts("");
        b[cnt=1]=1;
        rep(i,1,m-1) b[++cnt]=a[i];
        rep(i,1,(a[m]-1)/2) b[++cnt]=2;
        printf("%d\n",cnt);
        rep(i,1,cnt) printf("%d ",b[i]);
        return 0;
    }
    if(t==2){
        rep(i,1,m) if(a[i]&1){swap(a[1],a[i]);break;}
        rep(i,2,m) if(a[i]&1){swap(a[m],a[i]);break;}
        rep(i,1,m) printf("%d ",a[i]);puts("");
        b[cnt=1]=a[1]+1;
        rep(i,2,m-1) b[++cnt]=a[i];
        rep(i,1,(a[m]-1)/2) b[++cnt]=2;
        printf("%d\n",cnt);
        rep(i,1,cnt) printf("%d ",b[i]);
        return 0;
    }
    return 0;
}