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
int main()
{
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();sort(a+1,a+1+n);reverse(a+1,a+1+n);
	for(int i=1;i<n;i++)if(a[i+1]<i+1)
	{
		int f1=(a[i]-i)&1,u=i;
		while(u<n&&a[u+1]==i)++u;
		int f2=(u-i)&1;
		return puts((f1|f2)?"First":"Second"),0;
	}
	int f1=(a[n]-n)&1;
	puts(f1?"First":"Second");
	return 0;
}
