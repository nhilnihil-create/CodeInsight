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
const int MAXN=100005;
char ch[MAXN];
int SA[2][MAXN];
int main()
{
	scanf("%s",ch+1);int len=strlen(ch+1);
	for(int i=1;i<=len;i++)SA[0][i]=SA[0][i-1]+(ch[i]=='A');
	scanf("%s",ch+1);len=strlen(ch+1);
	for(int i=1;i<=len;i++)SA[1][i]=SA[1][i-1]+(ch[i]=='A');
	int Q=read();while(Q--)
	{
		int l=read(),r=read(),u=read(),v=read();
		int b1=(r-l+1-(SA[0][r]-SA[0][l-1]))+2*(SA[0][r]-SA[0][l-1]);
		int b2=(v-u+1-(SA[1][v]-SA[1][u-1]))+2*(SA[1][v]-SA[1][u-1]);
		if(abs(b1-b2)%3==0)puts("YES");
		else puts("NO");
	}
	return 0;
}

