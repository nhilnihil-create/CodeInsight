#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
const int N=100005;
int n,a,b;
int che[N];

bool mep(long long int x)
{
    long long int sum=0;
    for(int i=0; i<n; ++i)
    {
        long long t=(long long)che[i]-x*b;
        if(t>0)
        {
            sum+=(int)ceil((t*1.0)/(a-b));
            if(sum>x || sum<0)
                return false;
        }
    }
    return true;
}

int main()
{
    int ma=0;
    scanf("%d %d %d",&n,&a,&b);
    for(int i=0; i<n; ++i)
        scanf("%d",&che[i]),ma=max(ma,che[i]);
    long long l=0,r=ma;
    while(l<r)
    {
        long long mid=(l+r)/2;
        if(mep(mid)) r=mid;
        else l=mid+1;
    }
    printf("%d\n",r);
    return 0;
}
