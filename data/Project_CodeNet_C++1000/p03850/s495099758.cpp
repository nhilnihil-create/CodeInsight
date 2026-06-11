#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

const int MAXN = 100100;
typedef long long LL;
const LL INF = 1e16;
char opt[MAXN];
int n,kind = 0;
LL val[MAXN],ans = -INF,sum[MAXN];

template<typename T>
void read(T &x)
{
	x = 0;
	char ch = getchar();
	while(ch < '0' || ch > '9') ch = getchar();
	while(ch >= '0' && ch <= '9')
		x = x * 10 + ch - '0',ch = getchar();
}

void init()
{
	LL t1 = val[1],t2 = 0,temp;
	for(int i = 1;i <= n-1;i++)
	{
		if(opt[i] == '+')
		{
			t1 += val[i+1];
			continue;
		} 
		int now = i+1;temp = -val[i+1];
		while(now < n && opt[now] == '+')
		{
			now++;
			temp -= val[now];
		}
	//	printf("%lld\n",t1+t2+temp+sum[n]-sum[now]);
		ans = max(ans,t1 + t2 + temp + sum[n] - sum[now]);
		t2 -= val[i+1];
	}
	ans = max(ans,t1+t2);
}

int main()
{
	//freopen("T2.in","r",stdin);
	read(n);
	for(int i = 1;i <= n;i++)
	{
		scanf("%lld",&val[i]);
		sum[i] = sum[i-1] + val[i];
		if(i != n) cin >> opt[i];
	}
	init();
	printf("%lld\n",ans);
	return 0;
}
/*
5
1 - 100 - 50 - 10 - 5
*/
