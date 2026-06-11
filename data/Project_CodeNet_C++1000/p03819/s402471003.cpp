#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
const int N=200003;
int n,m,cnt,f[N],kq[N];
pair< pair<int,int>,int> p[N*17];
void ud(int i)
{
    for (;i<=m*2;i+=(i&-i)) f[i]++;
}
int tv(int i)
{
    int res=0;
    for (;i>0;i-=(i&-i)) res+=f[i];
    return res;
}
int main()
{
   
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        cnt++;
        cin>>p[cnt].S>>p[cnt].F.F;
        p[cnt].F.S=-1;
    }
    for (int i=2;i<=m;i++)
    for (int j=i;j<=m*2;j+=i)
    {
        cnt++;
        p[cnt].F.F=j-1;
        p[cnt].F.S=i;
        p[cnt].S=j-i+1;
    }
    sort(p+1,p+cnt+1);
    for (int i=1;i<=cnt;i++)
    {
        int cs=p[i].F.S;
        //cout<<p[i].F.F<<" "<<p[i].S<<" "<<p[i].F.S<<"\n";
        if (cs<0) ud(p[i].S);
        else
        {
            kq[cs]+=tv(p[i].F.F)-tv(p[i].S-1);
            //cout<<cs<<" "<<p[i].F.F<<" "<<p[i].S-1<<"\n";
        }
    }
    for (int i=1;i<=m;i++) cout<<n-kq[i]<<"\n";
    return 0;
}
