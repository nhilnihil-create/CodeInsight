#include <bits/stdc++.h>
using namespace std;
int n, a[100005], ans;
inline bool cmp(const int &a, const int &b) {return a > b;}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	sort(a + 1, a + 1 + n, cmp);
	for (int i = 1; i <= n; i ++)
		if (i + 1 > a[i + 1])
		{
			for (int j = i + 1; a[j] == i; j ++) ans ^= 1;
			ans |= (a[i] - i) & 1;
			puts(ans ? "First" : "Second");
			return 0;
		}
}