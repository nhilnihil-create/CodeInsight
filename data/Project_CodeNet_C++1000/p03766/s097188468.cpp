#include<cstdio>
#include<algorithm>
#define fo(i,a,b) for(i=a;i<=b;i++)
using namespace std;
typedef long long ll;
const int maxn=1000000+10,mo=1000000007;
int f[maxn*2],g[maxn*2];
int i,j,k,l,t,n,m,ans;
int main(){
    scanf("%d",&n);
    f[1]=1;
    fo(i,1,n){
        if (i>=3) (f[i]+=g[i-3])%=mo;
        (f[i]+=f[i-1])%=mo;
        g[i]=(g[i-1]+f[i])%mo;
    }
    fo(i,1,n-1) (ans+=(ll)f[i]*(n-1)%mo*(n-1)%mo)%=mo;
    fo(i,1,n-1) (ans+=(ll)f[i]*min(i+1,n-1)%mo)%=mo;
    (ans+=(ll)f[n]*n%mo)%=mo;
    (ans+=mo)%=mo;
    printf("%d\n",ans);
}