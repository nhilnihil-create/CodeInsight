#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<math.h>
using namespace std;
int d[100010],n,a,b;
bool judge(long long mid)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        long long t=(long long)d[i]-mid*b;
        if(t>0)
        {
            sum+=(int)ceil(t*1.0/(a-b));
            if(sum>mid||sum<0)
                return false;
        }
    }
    return true;
}
int main()
{
    long long l=0,r=0;
    cin>>n>>a>>b;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&d[i]);
        r=max(r,(long long)d[i]);
    }
    while(l<r)
    {
        long long mid=l+r>>1;
        if(judge(mid))
        r=mid;
        else l=mid+1;
    }
    cout<<r<<endl;
}
