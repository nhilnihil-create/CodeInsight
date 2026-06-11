#include<bits/stdc++.h>

using namespace std;
#define X first
#define Y second
#define pb push_back
typedef double db;
typedef long long ll;
typedef pair<int,int> P;
const int MAXN=2e5+10;
vector<int> v[MAXN];
ll res[MAXN];
int n,a[MAXN],dsp[MAXN],tot;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) 
        scanf("%d",&a[i]),dsp[++tot]=a[i];
    sort(dsp+1,dsp+n+1);tot=unique(dsp+1,dsp+n+1)-dsp-1;
    
    for(int i=1;i<=n;i++)
        a[i]=lower_bound(dsp+1,dsp+tot+1,a[i])-dsp,v[a[i]].pb(i);
    int now=0,mn=v[tot][0];
    for(int i=tot;i>=1;i--)
    {
        int d=dsp[i]-dsp[i-1];
        mn=min(mn,v[i][0]);
        now+=v[i].size();
        res[mn]+=1ll*now*d;
    }
    for(int i=1;i<=n;i++)
        printf("%lld\n",res[i]);
    return 0;
}