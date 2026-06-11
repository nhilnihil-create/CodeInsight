#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int maxn = 2e5+100;
LL a[maxn],sum[maxn],tot;
LL Min = 1000000000000000000LL;
int n;
int main()
{
   scanf("%d",&n);
   for(int i=1;i<=n;i++){
    scanf("%lld",&a[i]);
    sum[i]=sum[i-1]+a[i];
    tot+=a[i];
   }
   for(int i=1;i<n;i++){
    Min=min(Min,abs(2*sum[i]-tot));
   }
   printf("%lld\n",Min);
}
/*
1 2 3 4
4 2 1 3

0   6  7  6 7 0
n-2 3 n-1 2 n 1
↓
0 6 6 0 7 7
*/
