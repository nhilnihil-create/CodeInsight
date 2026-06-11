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
string s;
signed main()
{
    cin>>s;
    int n=s.length();
    for(ri int i=n-1;~i;)
    {
        //printf("%lld\n",i);
        if(i>=4 && s.substr(i-4,5)=="dream") i-=5;
        else if(i>=4 && s.substr(i-4,5)=="erase") i-=5;
        else if(i>=6 && s.substr(i-6,7)=="dreamer") i-=7;
        else if(i>=5 && s.substr(i-5,6)=="eraser") i-=6;
        else{
            puts("NO");
            return 0;
        }
        
    }
    puts("YES");
    return 0;
}