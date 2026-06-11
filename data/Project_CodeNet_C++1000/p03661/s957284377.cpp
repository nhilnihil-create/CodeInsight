#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <queue>
#include <stack>
#define sf(n) scanf("%d",&n);
#define sfl(n) scanf("%lld",&n);
#define pf(n) printf("%d",n);
#define pfl(n) printf("%lld",n);
#define pr printf("\n");
#define LL long long
using namespace std;

const LL maxn=2*1e5+5;
LL num[maxn];
LL sum[maxn];

int main(){
    LL n;
    scanf("%lld",&n);
    for(LL i=0;i<n;i++)
        scanf("%lld",&num[i]);

    sum[0]=num[0];

    for(LL i=1;i<n;i++){
        sum[i]+= (sum[i-1]+num[i]);
    }
    LL x,y;
    LL Min=1e18;

    for(LL i=0;i<n-1;i++){
        x=sum[i];
        y=sum[n-1]-sum[i];
        Min=min(Min,abs(x-y));
    }
    printf("%lld\n",Min);
    return 0;
}
