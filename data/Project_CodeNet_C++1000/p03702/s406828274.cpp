#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

typedef long long ll;
int num[200000];
int n,a,b;

bool judge(ll m)
{
    ll ty=m*b;
    ll sub=a-b;
    ll sum=0;
    for(int i=0;i<n;i++)
    {
        if(ty<num[i])
        {
            ll temp=num[i]-ty;
            sum+=temp/sub;
            if(temp%sub)
                sum++;
        }
    }
    if(sum<=m)
        return true;
    return false;
}

int main()
{
    ll Max=0;
    cin>>n>>a>>b;
    for(int i=0;i<n;i++)
    {
        cin>>num[i];
        Max+=num[i]/b+1;
    }
    sort(num,num+n);
    ll Min=1;
    while(Min<Max)
    {
        ll mid=(Max+Min)>>1;
        if(judge(mid))
            Max=mid;
        else
            Min=mid+1;
    }
    cout<<Min;
    return 0;
}
