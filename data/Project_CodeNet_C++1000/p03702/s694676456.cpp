#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
long long a,b,ans,n;
long long m[100001];
bool judge(long long x)
{
    long long temp=x*b,sub=a-b,sum=0;
    for(int i=0;i<n;i++)
    {
        if(m[i]-temp>0)
        {
            if((m[i]-temp)%sub)
                sum+=(m[i]-temp)/sub+1;
            else
                sum+=(m[i]-temp)/sub;
        }
    }
    if(sum<=x)
        return true;
    return false;
}
int main()
{
    long long right=0,left=1;
    scanf("%lld%lld%lld",&n,&a,&b);
    for(int i=0;i<n;i++)
        {
            scanf("%d",&m[i]);
            right+=m[i]/b+1;
        }
    sort(m,m+n);
    while(left<right)
    {
        long long mid=(left+right)>>1;
        if(judge(mid))
            right=mid;
        else
            left=mid+1;
    }
    printf("%d\n",left);

    return 0;
}