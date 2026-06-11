#include<cstdio>
#include<algorithm>
#define MN 2100001
using namespace std;
 
int n,m,a[MN];
long long sum1=0,sum2=0,mmh=1e18;
long long _abs(long long x){return x<0?-x:x;}
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]),sum2+=a[i];
    for (int i=1;i<n;i++) if (sum1+=a[i],_abs(sum2-sum1-sum1)<mmh) mmh=abs(sum2-sum1-sum1);
    printf("%d\n",mmh);
}