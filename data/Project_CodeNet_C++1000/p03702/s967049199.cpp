#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
int A,B,N;
int a[100005];

bool judge(long long x)
{
    long long sum=0;
    for(int i=0;i<N;i++)
    {
        long long t=a[i]-B*x;

        if(t>0)
        sum+=(int)ceil(t*1.0/(A-B));

        if(sum>x||sum<0)
            return false;
    }
    return true;
}
int main()
{
    int  imax=0;
 scanf("%d%d%d",&N,&A,&B);
 for(int i=0;i<N;i++)
    scanf("%d",&a[i]),imax=max(a[i],imax);
    long long l=0,r=imax;
    while(l<r)
    {
        long long mid=(l+r)/2;
        if(judge(mid))
            r=mid;
        else
            l=mid+1;
    }
    printf("%lld\n",r);
    return 0;
}
