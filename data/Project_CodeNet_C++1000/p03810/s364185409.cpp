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
inline int read()
{
	int f=1,x=0;char ch=getchar();
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
const int MAXN=100005;
int a[MAXN],n;
void A(){puts("First");exit(0);}
void B(){puts("Second");exit(0);}
void win(int o){o?B():A();}
int gcd(int a,int b){return a==0?b:gcd(b%a,a);}
void work(int now)
{
	int sum=0,val=0;bool tf=false;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==1)tf=true;
		sum^=(a[i]-1)&1;val+=(a[i]&1);
	}
	if(tf==true)(sum&1)?(win(now)):(win(now^1));
	if(val>1)((n-val)&1)?(win(now)):(win(now^1));
	for(int i=1;i<=n;i++)if(a[i]&1)a[i]--;int g=0;
	for(int i=1;i<=n;i++)g=gcd(g,a[i]);
	for(int i=1;i<=n;i++)a[i]/=g;
	work(now^1);
}
int main()
{
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	work(0);
	return 0;
}
