#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#define ll long long
using namespace std;
int a[100050];
int n,x,y;
bool judge(ll mid)
{
    ll cot=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]-y*mid>0)
        {
            int k=a[i]-y*mid;
            if(k%(x-y)==0) cot+=k/(x-y);
            else cot+=k/(x-y)+1;
        }
    }
    if(cot<=mid) return true;
    else return false;
}
int main()
{

    scanf("%d%d%d",&n,&x,&y);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    ll l=0,r=1000000000;
    while(l<r)
    {
        ll mid=(l+r)/2;
        if(judge(mid))
        {
            r=mid;
        }
        else l=mid+1;
    }
    printf("%lld\n",r);
}
