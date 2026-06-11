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
#define LL long long
#define mp(x,y) make_pair(x,y)
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;
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
const int MAXN=105;
LL n;
int is[MAXN],sta[MAXN];
int main()
{
	n=read();int mx=0;
	for(LL i=1;(i<<1)<=n;i<<=1)++mx;n-=1LL<<mx;
	int now=mx+2,tp=0,len=mx+1;
	for(int i=60;i>=0;i--)if(n&(1LL<<i))is[i]=sta[++tp]=now++,++len;
	pr2(len<<1);
	for(int i=0;i<=mx;i++)
	{
		if(i)pr1(i);
		if(is[i])pr1(is[i]);
	}
	for(int i=1;i<=mx;i++)pr1(i);
	pr1(mx+1);pr1(mx+1);
	for(int i=1;i<=tp;i++)pr1(sta[i]);puts("");
	return 0;
}
