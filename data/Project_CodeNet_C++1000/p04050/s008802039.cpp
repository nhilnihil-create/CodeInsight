#include<bits/stdc++.h>
using namespace std;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define sd(mark) scanf("%d",&mark)
#define ss(mark) scanf("%s",&mark)
#define slld(mark) scanf("%lld",&mark)
#define clr(mark) memset(mark,0,sizeof(mark))
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define sz(x) (int((x).size()))
#define PII pair<int,int>
#define PIL pair<int,long long>
#define PLL pair<long long,long long>
#define PIS pair<int,string>
#define MII map<int,int>
#define LL long long
#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,a,n) for (int i=(n)-1;i>=(a);i--)
#define FILEIO(name) \
    freopen(name".in", "r", stdin); \
    freopen(name".out", "w", stdout);
#define INF 2000000000 // 2 * 10^9
#define INFLL 1000000000000000000LL  // 10^18
#define mod 1000000007

#define N 1012345

vector<int> e,o,rsa,rsb;

void solve()
{
    int n,m,a,i;
    sd(n);
    sd(m);
    for(i=0;i<m;++i)
    {
        sd(a);
        if(a&1) o.PB(a);
        else    e.PB(a);
    }
    if(n==1)
    {
        printf("1\n1\n1\n");
        return;
    }
    if(m==1)
    {
        printf("%d\n",a);
        printf("2\n");
        printf("%d 1\n",a-1);
        return;
    }
    if(o.size()>2)
    {
        printf("Impossible\n");
        return;
    }
    int f,l;
    if(o.size()>=1)
        f = o[0];
    else
    {
        f = e.back();
        e.pop_back();
    }
    if(o.size()==2)
        l = o[1];
    else
    {
        l = e.back();
        e.pop_back();
    }
    rsa.PB(f);
    if(f>1) rsb.PB(f-1);
    for(i=0;i<e.size();++i)
    {
        rsa.PB(e[i]);
        rsb.PB(e[i]);
    }
    rsb.PB(2);
    rsa.PB(l);
    if(l>1) rsb.PB(l-1);
    for(i=0;i<rsa.size();++i)
        printf("%d ",rsa[i]);
    printf("\n");
    printf("%d\n",rsb.size());
    for(i=0;i<rsb.size();++i)
        printf("%d ",rsb[i]);
    printf("\n");
}

int main()
{
    int t = 1;
    //scanf("%d",&t);
    while(t--)
    {
        solve();
    }
}

