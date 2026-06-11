
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
const int N=1e5+3;
int a[N],d[N],c[N],b[N],tmp[N];
ll n,m,k,x;
void qmod(){
    while(k){
        if(k&1){
            for (int i=1; i<=n; i++)
                tmp[i]=b[c[i]];
            for (int i=1; i<=n; i++)
                b[i]=tmp[i];
        }
        k>>=1;
        for (int i=1; i<=n; i++)
            tmp[i]=c[c[i]];
        for (int i=1; i<=n; i++)
            c[i]=tmp[i];
    }
}
int main(){
    scanf("%lld",&n);
    for (int i=1; i<=n; i++){
        scanf("%d",&a[i]);
        d[i]=a[i]-a[i-1];
        tmp[i]=b[i]=c[i]=i;
    }
    scanf("%lld%lld",&m,&k);
    for (int i=1; i<=m; i++){
        scanf("%d",&x);
        swap(c[x],c[x+1]);
    }
    qmod();
    ll ans=0;
    for (int i=1; i<=n; i++){
        ans+=1ll*d[b[i]];
        printf("%lld.0\n",ans);
    }
    return 0;
}