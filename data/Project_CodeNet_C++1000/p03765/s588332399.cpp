#include <bits/stdc++.h>

using namespace std;
string s,t;
int n,x,y,u,v,co,can,sl,F[100005],T[100005],P[100005],vt,l,r,mid;
int main()
{
  
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>s>>t;
    cin>>n;
    s='.'+s;
    t='.'+t;
    for (int i=1;i<s.length();++i) F[i]=F[i-1]+1+(s[i]=='B');
    for (int i=1;i<t.length();++i)
    {
    P[i]=P[i-1]+(t[i]=='B');

    if (t[i]=='A') {sl=0;vt=i;T[i]=T[i-1]+1;}
    else
    {
        sl++;
        if (sl%2) T[i]=T[vt]+(sl+3)/2;
        else      T[i]=T[vt]+sl/2;
    }

    }
    while (n--)
    {
        cin>>x>>y>>u>>v;
        co=F[y]-F[x-1];
        can=0;
        vt=u-1;
        l=u;r=v;
        while (l<=r)
        {
            mid=(l+r)/2;
            if (P[mid]-P[u-1]==mid-u+1) {l=mid+1;vt=mid;}
            else r=mid-1;
        }
        sl=vt-u+1;
        if (sl%2) can=(sl+3)/2;
        else      can=sl/2;
        can+=T[v]-T[vt];
        if ((co-can)%3==0) cout<<"YES";else cout<<"NO";cout<<'\n';

    }

    return 0;
}
