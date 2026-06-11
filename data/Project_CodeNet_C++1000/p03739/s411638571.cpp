#include <bits/stdc++.h>

#define F first 
#define S second
#define PB push_back

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef priority_queue<int> HEAP;
typedef priority_queue<int, vector<int>, greater<int> > RHEAP;

const int N = 100010, M = 1010;

int n, t;
int a[N];
LL sum;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++ ) scanf("%d", &a[i]);
	
	LL res = 0LL;
	for (int i = 1, t = 1; i <= n; i ++ , t *= -1)
	{
		sum += a[i];
		if (t * sum <= 0) res += abs(t - sum), sum = t;
	}
	
	sum = 0LL;
	LL ans = 0LL;
	for (int i = 1, t = -1; i <= n; i ++ , t *= -1)
	{
		sum += a[i];
		if (t * sum <= 0) ans += abs(t - sum), sum = t;
	}
	
	printf("%lld\n", min(res, ans));
    return 0;
}