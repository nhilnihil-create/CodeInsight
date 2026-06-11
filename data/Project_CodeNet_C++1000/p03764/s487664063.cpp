#include<cstdio>
#include<algorithm>
#define MN 200001
using namespace std;
const int MOD=1e9+7;
typedef long long ll;
ll n,m,a[MN],b[MN],A=0,B=0;
int main(){
    
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
    for (int i=1;i<=m;i++) scanf("%lld",&b[i]);
    for (int i=1;i<n;i++) 
        A=((a[i+1]-a[i])*i%MOD*(n-i)+A)%MOD;
    for (int i=1;i<m;i++) 
        B=((b[i+1]-b[i])*i%MOD*(m-i)+B)%MOD;
    printf("%lld\n",A*B%MOD);
}