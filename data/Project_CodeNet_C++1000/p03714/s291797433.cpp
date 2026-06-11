#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<set>
using namespace std;

const long long inf=1e18;
const int maxn=3e5+5;

multiset <int> s;
multiset <int,greater<int> > t;
long long a[maxn],b[maxn],c[maxn],n,now,ans;

int main()
{
	ans=-inf;
    cin>>n;
    for(long long i=1;i<=n*3;i++)
    {
        scanf("%lld",&a[i]);
        s.insert(a[i]);
        now=now+a[i];
        if(s.size()>n)
        {
            now-=*s.begin();
            s.erase(s.begin());
        }
        b[i]=now;
    }
    now=0;
    for(long long i=n*3;i>=1;i--)
    {
        t.insert(a[i]);
        now=now+a[i];
        if(t.size()>n)
        {
            now-=*t.begin();
            t.erase(t.begin());
        }
        c[i]=now;
    }
    for(long long i=n;i<=n*2;i++)
    {
        ans=max(ans,b[i]-c[i+1]);
    }
    cout<<ans;
    return 0;
}