#include <bits/stdc++.h>
#define ri register
#define int long long
#define E (n+1)
using namespace std; const int N=200010;
inline int read()
{
    int s=0, w=1; ri char ch=getchar();
    while(ch<'0'||ch>'9') { if(ch=='-') w=-1; ch=getchar(); }
    while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch^48), ch=getchar();
    return s*w;
}
int h,w;
string s[N];
signed main()
{
    h=read(), w=read();
    for(ri int i=1;i<=h;i++) cin>>s[i];
    for(ri int i=1;i<=h*2;i++) cout<<s[(i+1)/2]<<endl;
    return 0;
}