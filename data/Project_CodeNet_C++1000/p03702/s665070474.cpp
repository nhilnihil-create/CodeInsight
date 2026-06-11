#include <iostream>
#include <cstring>
#include <cstdio>
#define MAX 100010

using namespace std;

int n;
long long a,b;
long long h[MAX];

bool Judge(long long x)
{
    long long re;
    long c=0;
    int i;
    for(i=0;i<n;i++)
    {
        re=h[i]-x*b;
        if(re<=0)
            continue;
        else
            {
                c+=re/(a-b);
                if(re%(a-b)!=0)
                    c++;
                if(c>x)
                    return false;
            }
    }
    return true;
}

int main()
{
    long long l=0,r=1e9,ans,count;
    cin>>n>>a>>b;
    for(int i=0;i<n;i++)
    {
        cin>>h[i];
    }
    ans=r;
    while(l<=r)
    {
        count=(l+r)/2;
        if(Judge(count))
        {
            r=count-1;
            ans=min(count,ans);
        }
        else
            l=count+1;
    }
    cout<<ans<<endl;
    return 0;
}
