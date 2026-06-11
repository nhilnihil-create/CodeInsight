#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<map>
#include<ctime>
#define up(i,x,y) for(int i = x;i <= y;i ++)
#define down(i,x,y) for(int i = x;i >= y;i --)
#define mem(a,b) memset((a),(b),sizeof(a))
#define mod(x) ((x)%MOD)
#define lson p<<1
#define rson p<<1|1
using namespace std;
typedef long long ll;
const int SIZE = 50010;
const int INF = 2147483640;
const double eps = 1e-8;

inline void RD(int &x)
{
    x = 0;  char c; c = getchar();
    bool flag = 0;
    if(c == '-')    flag = 1;
    while(c < '0' || c > '9')   {if(c == '-')   {flag = 1;} c = getchar();}
    while(c >= '0' && c <= '9') x = (x << 1) + (x << 3) + c - '0',c = getchar();
}
ll base = 20000;
ll a[SIZE],b[SIZE];
int in[SIZE];
int n;

int main(int argc, char const *argv[])
{
	scanf("%d",&n);
	for(int i = 1;i <= n;i ++)
	{
		scanf("%d",&in[i]);
	}
	for(int i = 1;i <= n;i ++)
	{
		a[in[i]] = 1ll * (in[i]-1) * base + (ll)i;
		b[in[i]] = 1ll * (n-in[i]) * base + (ll)i;
	}
	for(int i = 1;i <= n;i ++)
	{
		printf("%lld%c",a[i],i == n ? '\n' : ' ');
	}
	for(int i = 1;i <= n;i ++)
	{
		printf("%lld%c",b[i],i == n ? '\n' : ' ');
	}
	return 0;
}