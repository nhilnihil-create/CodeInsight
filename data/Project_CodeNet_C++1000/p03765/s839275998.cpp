#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const int N=1e5+10,inf=3e6;
string s,t;
int ps1[N],ps2[N],q,n,m;
int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>s>>t;
    n=s.length();
    m=t.length();
    for (int i=1;i<=n;i++)
        if (s[i-1]=='A') ps1[i]=ps1[i-1]+1;
        else ps1[i]=ps1[i-1]-1;
    for (int i=1;i<=m;i++)
        if (t[i-1]=='A') ps2[i]=ps2[i-1]+1;
        else ps2[i]=ps2[i-1]-1;
    cin>>q;
    for (int i=1,u,v,l,r;i<=q;i++)
    {
        cin>>l>>r>>u>>v;
        if ((ps1[r]-ps1[l-1]+inf)%3==(ps2[v]-ps2[u-1]+inf)%3) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
