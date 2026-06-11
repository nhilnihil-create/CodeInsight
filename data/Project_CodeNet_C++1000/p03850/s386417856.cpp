#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

const LL maxn = 100005;
const LL inf = 0x3f3f3f3f;

LL op[maxn];
LL a[maxn];
LL qzhh[maxn];
LL yuan[maxn];
LL lstt[maxn];
char s[3];
LL n;

int main()
{
	scanf("%lld", &n);
	scanf("%lld", &a[1]);
	qzhh[1] = yuan[1] = a[1];
	op[1] = 1;
	LL ans = 0;
	for(LL i = 2; i <= n; ++i)
	{
		scanf("%s%lld", s, &a[i]);
		op[i] = (s[0] == '+');
		qzhh[i] = qzhh[i - 1] + a[i];
		yuan[i] = yuan[i - 1] + (op[i] ? a[i] : -a[i]);
	}
	op[n + 1] = op[n + 2] = 0;
	qzhh[n + 1] = qzhh[n + 2] = qzhh[n];
	yuan[n + 1] = yuan[n + 2] = yuan[n];
	n += 2;
	LL lst = n + 1;
	for(LL i = n; i; --i)
	{
		if(!op[i])
		{
			lstt[i] = lst;
			lst = i;
		}
	}
//	cout << "qzhh = ";
//	for(LL i = 1; i <= n; ++i)
//		cout << qzhh[i] << ' ';
//	cout << endl;
//	cout << "yuan = ";
//	for(LL i = 1; i <= n; ++i)
//		cout << yuan[i] << ' ';
//	cout << endl;
//	cout << "lstt = ";
//	for(LL i = 1; i <= n; ++i)
//		cout << lstt[i] << ' ';
//	cout << endl;
	for(LL i = lst; lstt[i] <= n; i = lstt[i])
	{
		LL l = i, r = lstt[i];
		ans = max(ans, yuan[l - 1] - (qzhh[r - 1] - qzhh[l - 1]) + qzhh[n] - qzhh[r - 1]);
//		cout << l << ' ' << r << ' ' << ans << endl;
	}
	printf("%lld\n", ans);
	return 0;
}