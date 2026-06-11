#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
using namespace std;
long long int n,a,b,m[200000];
int erfen(long long int mid)
{
    long long int sum=0;
    for(int i=0; i<n; i++)
    {
        long long int t=(long long int )m[i]-mid*b;
        if(t>0)
        {
            sum+=(int)ceil(t*1.0/(a-b));
            if(sum>mid||sum<0)
            {
                return 0;
            }
        }
    }
    return 1;
}

int main()
{
    while(scanf("%d %d %d",&n,&a,&b)!=EOF)
    {
       long long  int p=0;int i;
        for( i=0;i<n;++i)
        {
            scanf("%d",&m[i]);
            p=max(p,m[i]);
        }
        long long int l=0,r=p;
        while(l<r)
        {
            long long mid=l+r>>1;
            if(erfen(mid)==1)
            {
                r=mid;
            }
            else
            {
                l=mid+1;
            }
        }
        cout<<r<<endl;
    }
    return 0;
}
