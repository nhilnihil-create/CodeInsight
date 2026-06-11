#include<cstdio>
#include<algorithm>
#define MN 200001
using namespace std;
 
const int MOD=1e9+7;
int n,m,a[MN],b[MN],A=0,B=0;
int main(){
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);sort(a+1,a+1+n);
    for (int i=1;i<=m;i++) scanf("%d",&b[i]);sort(b+1,b+1+m);
    for (int i=1;i<n;i++) A=(1LL*(a[i+1]-a[i])*i%MOD*(n-i)+A)%MOD;
    for (int i=1;i<m;i++) B=(1LL*(b[i+1]-b[i])*i%MOD*(m-i)+B)%MOD;
    printf("%lld\n",1ll*A*B%MOD);
}