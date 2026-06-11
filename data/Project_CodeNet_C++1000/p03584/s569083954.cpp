#include<bits/stdc++.h>
using namespace std;
int n,k;
int upbit(int x)
{
    for(int i=30;i>=0;i--)
        if(x>>i&1) return i;
    return -1;
}
vector<pair<int,int>>v[55];
long long sum[55];
int main()
{
    //freopen("01.txt","r",stdin);
    scanf("%d%d",&n,&k);
    long long ans=0,res=0;
    int u=upbit(k);
    for(int i=1;i<=n;i++)
    {
        int a,b;scanf("%d%d",&a,&b);
        int k=upbit(a);
        if(k==-1||(a&k)==a) res+=b;
        else v[k].push_back({a,b}),sum[k]+=b;
    }
    for(int i=u;i>=0;i--)
        if(k>>i&1)
        {
            long long s=0;
            for(int j=i-1;j>=0;j--)
                s+=sum[j];
            ans=max(ans,res+s);
            for(pair<int,int>x:v[i])
            {
                x.first^=1<<i;
                int k=upbit(x.first);
                if(k==-1) res+=x.second;
                else v[k].push_back(x),sum[k]+=x.second;
            }
        }
    ans=max(ans,res);
    printf("%lld\n",ans);
}
