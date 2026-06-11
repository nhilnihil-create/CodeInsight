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
const int MAXN=505;
int mp[MAXN][MAXN],n,m,A,B;
int main()
{
	n=read();m=read();
	A=read();B=read();
	if(!(n%A)&&!(m%B))return puts("No"),0;
//	puts("Yes");
	int d=2000;
	int cnt=n*m*d;
	for(int i=1;i*A<=n;i++)for(int j=1;j*B<=m;j++)
		mp[i*A][j*B]=-(A*B-1)*d-1,cnt-=(A*B-1)*d+d+1;
	if(cnt<=0)return puts("No"),0;
	puts("Yes");
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)pr1(!mp[i][j]?d:mp[i][j]);
		puts("");
	}
	return 0;
}
