#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,cnt;
int main()
{
    scanf("%d",&n);long long ans=0;
    for(int i=1,w;i<=n;i++)
    {
        scanf("%d",&w),ans+=w>>1;
        if(!w)ans+=cnt>>1,cnt=0;
        else cnt+=w&1;
    }
    ans+=cnt>>1;
    cout<<ans<<endl;
}