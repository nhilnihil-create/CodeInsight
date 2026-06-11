// This amazing code is by Eric Sunli Chen.
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
using namespace std;
template<typename T> void get_int(T &x)
{
	char t=getchar();
	bool neg=false;
	x=0;
	for(; (t>'9'||t<'0')&&t!='-'; t=getchar());
	if(t=='-')neg=true,t=getchar();
	for(; t<='9'&&t>='0'; t=getchar())x=x*10+t-'0';
	if(neg)x=-x;
}
template<typename T> void print_int(T x)
{
	if(x<0)putchar('-'),x=-x;
	short a[20]= {},sz=0;
	while(x>0)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1; i>=0; i--)putchar('0'+a[i]);
}
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define get1(a) get_int(a)
#define get2(a,b) get1(a),get1(b)
#define get3(a,b,c) get1(a),get2(b,c)
#define printendl(a) print_int(a),puts("")
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;
const int inf=0x3f3f3f3f;
const LL Linf=1ll<<61;
const double pi=acos(-1.0);

const int mod=1e9+7;

inline void add(int &x,int y){x+=y;if(x>=mod)x-=mod;}
char s[5111];
int n,m,dp[5111][5111];
int main()
{
	get1(n);scanf("%s",s+1);m=strlen(s+1);
	dp[0][0]=1;
	for(int i=0;i<n;i++)for(int j=0;j<=n;j++)
	{
		//backspace
		add(dp[i+1][j-(j>0)],dp[i][j]);
		//0/1
		add(dp[i+1][j+1],dp[i][j]);
		add(dp[i+1][j+1],dp[i][j]);
	}
	for(int i=1;i<=m;i++)dp[n][m]=1ll*dp[n][m]*(mod+1)/2%mod;
	printendl(dp[n][m]);
	return 0;
}