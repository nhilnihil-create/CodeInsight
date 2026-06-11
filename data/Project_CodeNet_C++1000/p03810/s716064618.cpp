#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b)
{
	for (;;)
	{
		if (a < b)swap(a, b);
		a %= b;
		if (a == 0)return b;
	}
}
ll dat[100000];
int main()
{
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)scanf("%lld", &dat[i]);
	int ans = -1, tmp = 0;
	for (;;)
	{
		int cnt = 0, t = 0;
		for (int i = 0; i < num; i++)cnt += (dat[i] % 2 == 0), t += (dat[i] == 1);
		if (cnt % 2 == 1)ans = tmp;
		else if (cnt != num - 1 || t>0)ans = 1 ^ tmp;
		else
		{
			ll g = dat[0] / 2 * 2;
			for (int i = 0; i < num; i++)g = gcd(dat[i] / 2 * 2, g);
			for (int i = 0; i < num; i++)dat[i] /= g;
		}
		if (ans != -1)break;
		tmp = 1 ^ tmp;
	}
	printf(ans ? "Second\n" : "First\n");
}