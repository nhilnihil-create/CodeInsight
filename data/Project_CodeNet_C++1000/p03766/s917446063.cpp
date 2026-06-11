#include<cstdio>
#include<algorithm>
#define MN 1000001
using namespace std;
 
const int MOD=1e9+7;
int n,f[MN],m;
inline void M(int &x){while(x>=MOD)x-=MOD;}
int main(){
    int i,j;
    scanf("%d",&n);f[n]=n;m=n-1;
    for (i=n-1;i;i--) f[i]=1LL*(n-1)*(n-1)%MOD,M(f[i]+=f[i+1]),M(f[i]+=m),M(m+=(i+2>n?1:f[i+2])-1);
    printf("%d\n",f[1]);
}