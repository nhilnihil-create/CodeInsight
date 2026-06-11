//xtwakioi! xtwddYnoi(双重含义)!
#include <bits/stdc++.h>
#define ri register
#define int long long
#define E (n+1)
using namespace std;
inline int read()
{
    int s=0, w=1; ri char ch=getchar();
    while(ch<'0'||ch>'9') { if(ch=='-') w=-1; ch=getchar(); }
    while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch^48), ch=getchar();
    return s*w;
}
string s,t;
signed main()
{
    cin>>s>>t;
    int n=s.length(), m=t.length();
    int p,q; p=q=0;
    for(ri int i=0;i<n+m;i++)
    {
        if(i&1ll) cout<<t[q++];
        else cout<<s[p++];
    }
    cout<<endl;
    return 0;
}