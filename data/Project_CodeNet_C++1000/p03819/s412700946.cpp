#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const int N=3e5+10;

int n,m,ans[N],bit[N],ps[N];
vector<pii> Q[N];
vector<int> inter[N];

void add(int v,int x)
{
    for (int i=v;i<=m;i+=(i&-i)) bit[i]+=x;
}

int get(int v)
{
    int res=0;
    for (int i=v;i;i-=(i&-i)) res+=bit[i];
    return res;
}

void read()
{
    cin>>n>>m;
    for (int i=1,l,r;i<=n;i++) cin>>l>>r,inter[l].pb(r),add(r,1);
}

void process()
{
    for (int i=m;i;i--) ps[i]=ps[i+1]+inter[i].size();
    for (int i=1;i<=m;i++)
        for (int j=i;j<=m;j+=i) Q[j-i+1].pb(mp(j,i));
    for (int i=1;i<=m;i++)
    {
        for (pii x : Q[i])
            ans[x.se]+=get(m)-get(x.fi-1)-ps[x.fi+1];
        for (int x : inter[i]) add(x,-1);
    }
    for (int i=1;i<=m;i++) cout<<ans[i]<<"\n";
}

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    read();
    process();
    return 0;
}
