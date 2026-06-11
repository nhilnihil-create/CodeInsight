#include <stdio.h>
#include <string.h>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>
#define LL long long
using namespace std;
LL N,A,B;
LL a[100005];
int main()
{
    int judge(LL x);
    scanf("%lld%lld%lld",&N,&A,&B);
    LL right=0;
    for(LL i=1; i<=N; i++)
    {
        scanf("%lld",&a[i]);
        right+=a[i]/B+1;
    }

    sort(a+1,a+1+N);
    LL left=1;
    while(left<right)
    {
        LL mid=(left+right)>>1;
        if(judge(mid)==1)
            right=mid;
        else
            left=mid+1;
    }
    printf("%lld\n",left);
    return 0;
}
int  judge(LL x)
{
    LL sum=0;
    LL b=x*B;
    LL c=A-B;
    for(LL i=1; i<=N; i++)
    {
        if(a[i]>b)
        {
            if((a[i]-b)%c)
                sum+=(a[i]-b)/c+1;
            else
                sum+=(a[i]-b)/c;
        }
    }
    if(sum<=x)
        return 1;
    else
        return 0;

}
