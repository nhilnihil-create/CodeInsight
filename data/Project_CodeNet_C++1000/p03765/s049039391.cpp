#include <bits/stdc++.h>
using namespace std;
string a,b;
int f[100001],g[100001],i,l1,r1,l2,r2,q;
int main()
{
  //  freopen("ntu.inp","r",stdin);
  //  freopen("ntu.out","w",stdout);
    cin>>a>>b;
    a=" "+a; b=" "+b;
    for(i=1;i<a.length();i++)
        if(a[i]=='A') f[i]=(f[i-1]+2)%3;
        else f[i]=(f[i-1]+1)%3;
    for(i=1;i<b.length();i++)
        if(b[i]=='A') g[i]=(g[i-1]+2)%3;
        else g[i]=(g[i-1]+1)%3;
    cin>>q;
    while(q--)
    {
        cin>>l1>>r1>>l2>>r2;
      //  cerr<<f[r1]-f[l1-1]+3)%3<<" "<<(g[r2]-g[l2-1]+3)%3)<<'\n';
        if(abs((f[r1]-f[l1-1]+3)%3-(g[r2]-g[l2-1]+3)%3)%3==0) cout<<"YES"<<'\n'; else cout<<"NO"<<'\n';
    }
}
