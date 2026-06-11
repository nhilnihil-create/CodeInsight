#include<bits/stdc++.h>
using namespace std;
#define int long long
#define forinc(i,a,b) for(int i=a;i<=b;++i)
#define fordec(i,a,b) for(int i=a;i>=b;--i)
#define forv(i,x) for(auto &i:x)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l,int r)
{
    return l+rng()%(r-l+1);
}
#define in ({int x=0;int c=getchar(),n=0;for(;!isdigit(c);c=getchar()) n=(c=='-');for(;isdigit(c);c=getchar()) x=x*10+c-'0';n?-x:x;})
#define pii pair<int,int>
#define fi first
#define se second
#define batbit(i,x) (x|(1ll<<i))
#define getbit(i,x) ((x>>i)&1)

const int mn=1e5+10;
string s,t;
int f[mn],g[mn],q;

main()
{
    cin >> s >> t;
    int n=s.size(),m=t.size();
    s=' '+s,t=' '+t;
    forinc(i,1,n) f[i]=f[i-1]+s[i]-'A'+1;
    forinc(i,1,m) g[i]=g[i-1]+t[i]-'A'+1;
    cin >> q;
    while(q--)
    {
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        if((f[b]-f[a-1])%3==(g[d]-g[c-1])%3) cout << "YES\n";
        else cout << "NO\n";
    }
}
