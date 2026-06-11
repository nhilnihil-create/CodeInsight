#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 20;
char ans[maxn];
int ly[maxn], ry[maxn];
int check(ll x, ll y)
{
	if(x <= y && to_string(x) <= to_string(y)) return 1;
	if(x > y && to_string(x) > to_string(y)) return 1;
	return 0;
}
int main()
{
	ll l, r = 1;
	for(int i = 1; i <= 10; ++i)
	{
		printf("? %lld\n", r);
		fflush(stdout);
		scanf("%s", ans);
		ly[i] = (ans[0] == 'Y');
		
		r = r * 10; 
		
		printf("? %lld\n", r - 1);
		fflush(stdout);
		scanf("%s", ans);
		ry[i] = (ans[0] == 'Y');
	}
	int pos;
	for(int i = 10; i; --i)
		if(ly[i] + ry[i] != ly[i - 1] + ry[i - 1])
		{
			if(ly[i] + ry[i] == 2) pos = i;
			else pos = i - 1;
			break;
		}
	r = 1;
	while(pos--) r *= 10;
	l = r / 10;
	r = r - 1;
	while(l <= r)
	{
		ll mid = l + r >> 1;
		
		printf("? %lld\n", mid * 10);
		fflush(stdout);
		scanf("%s", ans);
		
		if(ans[0] == 'Y') r = mid - 1;
		else l = mid + 1;
	}
	printf("! %lld\n", l);
	return 0;
}