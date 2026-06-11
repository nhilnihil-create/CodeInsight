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
struct edge{int x,y,next;}a[2*MAXN];int len,last[MAXN];
void ins(int x,int y){len++;a[len].x=x;a[len].y=y;a[len].next=last[x];last[x]=len;}
int sg[MAXN];
void dfs(int x,int fa)
{
	for(int k=last[x];k;k=a[k].next)
	{
		int y=a[k].y;
		if(y!=fa)dfs(y,x),sg[x]^=(sg[y]+1);
	}
}
int n;
int main()
{
	n=read();
	for(int i=1;i<n;i++)
	{
		int x=read(),y=read();
		ins(x,y);ins(y,x);
	}dfs(1,0);
	puts(sg[1]?"Alice":"Bob");
	return 0;
}
