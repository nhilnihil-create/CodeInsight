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
const int N = 1e5;
int n,m;
int a[N],b[N],t[N];
int main()
{
    n=read(),m=read();
    int fl=0;
    F(m) {
        a[i]=read();
        if(a[i]%2==1) t[++fl]=i;
        if(fl>2) {cout<<"Impossible";return 0;}
    }
    if(fl>=1) swap(a[1],a[t[1]]);
    if(fl>=2) swap(a[m],a[t[2]]);
    if(m==1&&a[1]==1) {cout<<1<<endl<<1<<endl<<1;return 0;}
    F(m) cout<<a[i]<<" ";cout<<endl;
    if(m==1) {cout<<2<<endl<<1<<" "<<a[1]-1;return 0;}
    cout<<(a[m]>1?m:m-1)<<endl<<a[1]+1<<" "; 
    F(m-2) cout<<a[i+1]<<" ";if(a[m]>1)cout<<a[m]-1;
    return 0;
}