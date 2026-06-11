#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;

#define dbg(x1) cout<<#x1<<" = "<<(x1)<<endl
#define dbg2(x1,x2) cout<<#x1<<" = "<<(x1)<<" "<<#x2<<" = "<<(x2)<<endl
#define dbg3(x1,x2,x3) cout<<#x1<<" = "<<(x1)<<" "<<#x2<<" = "<<(x2)<<" "<<#x3<<" = "<<(x3)<<endl
map<int,int> mp;
map<int,ll> mp2;
int lowbit(int x) {return x&(-x);}
void add(int x,int val)
{
    while(x<=1000000000)
    {
        mp[x]++;
        mp2[x]+=val;
        x+=lowbit(x);
    }
}
int sum(int x)
{
    int ans=0;
    while(x>0)
    {
        ans+=mp[x];
        x-=lowbit(x);
    }
    return ans;
}
ll sum2(int x)
{
    ll ans=0;
    while(x>0)
    {
        ans+=mp2[x];
        x-=lowbit(x);
    }
    return ans;
}
int ct[maxn],pre[maxn],a[maxn];
ll ans[maxn],nx[maxn],ct2[maxn];
set<int> s;
map<int,int> pos;
int main() {
    //freopen(".in", "r", stdin);
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=n;i>=1;i--) nx[i]=nx[i+1]+a[i];
    for(int i=n;i>=1;i--)
    {
        ct[i]=(n-i+1) - sum(a[i]-1);
        ct2[i]= nx[i] - sum2(a[i]-1) - 1LL*a[i]*ct[i];
        //dbg2(i,ct2[i]);
        add(a[i],a[i]);
    }
    for(int i=1;i<=n;i++)
    {
        set<int>::iterator it = s.upper_bound(-a[i]);
        if(it!=s.end()) pre[i]=pos[-(*it)];
        if(pos.find(a[i])==pos.end()) pos[a[i]]=i;
        s.insert(-a[i]);
    }
    int mx=0,ps=-1;
    for(int i=1;i<=n;i++)
    {
        if(a[i]>mx) mx=a[i],ps=i;
    }
    ct2[0] = nx[1];
    while(ps!=0)
    {
        int nx=pre[ps];
        ans[ps] += (ct2[nx] - ct2[ps]);
        ps = nx;
    }
    for(int i=1;i<=n;i++) printf("%lld\n",ans[i]);
    return 0;
}


