#include <bits/stdc++.h>

using namespace std;
string s,t;
int n,m;
int p1[1000005];
int p2[1000005];
int q;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>s;
    cin>>t;
    n=s.size();
    s=" "+s;
    m=t.size();
    t=" "+t;
    for (int i=1;i<=n;i++)
    {
        if (s[i]=='A') p1[i]=p1[i-1]+1;
        else p1[i]=p1[i-1]-1;
    }
    for (int i=1;i<=m;i++)
    {
        if (t[i]=='A') p2[i]=p2[i-1]+1;
        else p2[i]=p2[i-1]-1;
    }
    cin>>q;
    while (q--)
    {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        int s1=p1[b]-p1[a-1];
        int t1=p2[d]-p2[c-1];
        if (s1<0) s1=3-(abs(s1)%3);
        else s1=s1%3;
        s1%=3;
        if (t1<0) t1=3-(abs(t1)%3);
        else t1=t1%3;
        t1%=3;
        //cout<<s1<< " "<<t1<<'\n';
        if (s1==t1) cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
    }
    return 0;
}
