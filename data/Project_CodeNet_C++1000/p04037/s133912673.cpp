#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;
int n, ct, pnt, a[Maxn];
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	sort(a + 1, a + 1 + n, greater <int> ());
	pnt = n; 
	for (int i = 1; i <= n; i++)
		if (a[i] < i)
		{
			pnt = i - 1;
			break;
		}
	for (int i = pnt + 1; i <= n; i++)
		if (a[i] == pnt) ct++;
	puts((((a[pnt] - pnt) & 1) || (ct & 1)) ? "First" : "Second");
	return 0;
}