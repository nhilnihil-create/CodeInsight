#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
#include<ctime>
#include<map>
#include<bitset>
#include<set>
#include<assert.h>
#include<chrono>
#include<random>
#define LL long long
#define mp(x,y) make_pair(x,y)
#define pll pair<long long,long long>
#define pii pair<int,int>
#define SZ(x) ((int)x.size())
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
inline LL read()
{
	LL f=1,x=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int stack[20];
template<typename T>inline void write(T x)
{
	if(x<0){putchar('-');x=-x;}
    if(!x){putchar('0');return;}
    int top=0;
    while(x)stack[++top]=x%10,x/=10;
    while(top)putchar(stack[top--]+'0');
}
template<typename T>inline void pr1(T x){write(x);putchar(' ');}
template<typename T>inline void pr2(T x){write(x);putchar('\n');}
template<typename T>inline void chkmin(T &x,T y){x=x<y?x:y;}
template<typename T>inline void chkmax(T &x,T y){x=x>y?x:y;}
const int MAXN=300005;
int S[MAXN],n,m;
int lowbit(int x){return x&-x;}
void modify(int x,int c){for(;x<=m;x+=lowbit(x))S[x]+=c;}
int qry(int x){int ret=0;for(;x>=1;x-=lowbit(x))ret+=S[x];return ret;}
vector<pii> vec[MAXN];
int ans[MAXN];
int main()
{
	n=read();m=read();
	for(int i=1;i<=n;i++)
	{
		int l=read(),r=read();
		vec[r-l+1].emplace_back(mp(l,r));
		modify(l,1);modify(r+1,-1);
	}
	int pres=0;
	for(int i=m;i>=1;i--)
	{
		int sum=0;pres+=SZ(vec[i]);
		for(auto p:vec[i])modify(p.first,-1),modify(p.second+1,+1);
		for(int j=1;i*j<=m;j++)sum+=qry(j*i);
		ans[i]=sum+pres;
	}
	for(int i=1;i<=m;i++)pr2(ans[i]);
	return 0;
}

