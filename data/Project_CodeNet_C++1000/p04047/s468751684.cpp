#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<bitset>
#include<cstdlib>
#include<cmath>
#include<set>
#include<list>
#include<deque>
#include<map>
#include<queue>
#define F(x) for(int i=1;i<=(x);i++)
#define fer(i,n) for(int i=1;i<=(n);i++)
#define FIN  {freopen("1.in","r",stdin);}
#define FOUT {freopen("1.out","w",stdout);}
#define OUT(x)  {cout<<"#x"<<" : "<<x<<endl;}
#define ERR(x)  {cout<<"#error:"<<x;while(1);}
typedef long long ll;
typedef unsigned long long ull;
#define se second
#define fi first
#define make_pair mkp
#define mid ((l+r)>>1)
const int MaxInt = -1u>>1;
const int Max_ = 0x3f3f3f;
const double eps = 1e-6;
const double pi = acos(-1);
using namespace std;
inline int read()
{
    char ch=getchar();int f=1,g=0;
    for(;!isdigit(ch);ch=getchar()) if(ch=='-') f=-1;
    for(;isdigit(ch);ch=getchar()) g=g*10+(ch^48);
    return g*f;
}
const int N = 205;
int n,m;
int a[N];
int main()
{
    n=read();
    F(n*2) a[i]=read();
    sort(a+1,a+1+2*n);
    int ans=0;
    F(n) ans+=a[i*2-1];
    cout<<ans;
    return 0;
}