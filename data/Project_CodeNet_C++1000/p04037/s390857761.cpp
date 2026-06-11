#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int a[N];

int main(){
	int n, x, y, p, len1, len2;
	scanf("%d",&n);
	for (int i = 1; i <= n; i++) scanf("%d",&a[i]);
	sort(a + 1, a + n + 1, [&](int x, int y){return x > y;});
	x = y = 0;
	while (a[x + 2] > y + 1) x++, y++;
	len1 = 0; p = x;
	while (y < a[p + 2]) p++;
	len1 = p - x; len2 = a[x + 1] - y - 1;
	if (len1 % 2 == 0 && len2 % 2 == 0) printf("Second\n");
	else printf("First\n");
	return 0;
}