#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#define ll long long

using namespace std;
ll n,a,b,i,j;
ll mid,r,s,l,t,num;
ll h[1000010],h1[1000010];

bool jud(long long mid)
{
    s=b*mid;
    t=a-b;
    for(j=0;j<n;j++)
    {
        h1[j]=h1[j]-s;
        if(h1[j]<=0)
            continue;
            if(h1[j]%t==0)
                {
                    num=h1[j]/t;
                }
            else
                {
                    num=h1[j]/t+1;
                }
            mid=mid-num;
    }
    if(mid>=0)
        return true;
    else
        return false;
}

int main()
{
    scanf("%d%d%d",&n,&a,&b);
    for(i=0;i<n;i++)
    {
        scanf("%d",&h[i]);
        h1[i]=h[i];
    }
    sort(h,h+n);
    sort(h1,h1+n);
    r=h[n-1];
    //cout<<r<<endl;
    l=0;
    while(r-l>1)
    {
        mid=(r+l)/2;
        if(jud(mid))
            r=mid;
        else
            l=mid;

        for(i=0;i<n;i++)
            h1[i]=h[i];
    }
    printf("%d\n",r);
    return 0;
}
