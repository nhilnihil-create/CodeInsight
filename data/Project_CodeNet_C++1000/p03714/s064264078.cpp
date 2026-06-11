#include <bits/stdc++.h>
using namespace std;

int n;
priority_queue<long long,vector<long long>,greater<long long> > p1;
priority_queue<long long> p2;
long long num=0;
long long r[400005];
long long l[400005];
long long a[400005];

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=3*n;i++)
        scanf("%lld",&a[i]);
    for(int i=1;i<=3*n;i++)
    {
        if(p1.size()==n)
        {
            if(p1.top()<a[i])
            {
                num-=p1.top();
                p1.pop();
                p1.push(a[i]);
                num+=a[i];
            }
        }
        else
        {
            num+=a[i];
            p1.push(a[i]);
        }
        if(p1.size()==n)l[i]=num;
        if(p1.size()!=n)l[i]=-1e17;
    }
    num=0;
    for(int i=3*n;i>=1;i--)
    {
        if(p2.size()==n)
        {
            if(p2.top()>a[i])
            {
                num-=p2.top();
                p2.pop();
                p2.push(a[i]);
                num+=a[i];
            }
        }
        else
        {
            num+=a[i];
            p2.push(a[i]);
        }
        if(p2.size()==n)r[i]=num;
        if(p2.size()!=n)r[i]=1e17;
    }
    long long ans=-1e17;
    for(int i=1;i<3*n;i++)
        ans=max(ans,l[i]-r[i+1]);
    printf("%lld",ans);
    return 0;
}
