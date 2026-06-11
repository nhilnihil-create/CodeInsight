#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;
typedef long long ll;
const int maxN=3e5+5;

multiset <int> s;
multiset <int,greater<int> > t;
ll a[maxN],b[maxN],c[maxN];

int main()
{
    ll k,n,now=0,ans=-1e18;
    cin>>n;
    for(k=1;k<=n*3;k++)
    {
        cin>>a[k];
        s.insert(a[k]);
        now+=a[k];
        if(s.size()>n)
        {
            now-=*s.begin();
            s.erase(s.begin());
        }
        b[k]=now;
    }
    now=0;
    for(k=n*3;k>=1;k--)
    {
        t.insert(a[k]);
        now+=a[k];
        if(t.size()>n)
        {
            now-=*t.begin();
            t.erase(t.begin());
        }
        c[k]=now;
    }
    for(k=n;k<=n*2;k++)
    {
        ans=max(ans,b[k]-c[k+1]);
    }
    cout<<ans;
    return 0;
}
