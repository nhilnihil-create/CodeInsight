#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

int n, a[MAXN];
int f[MAXN];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	sort(a+1, a+n+1);
	for (int i = 0; i < n; i++) {
		f[i] = a[n-i]-1;
		// cerr << f[i] << " ";
	}
	// cerr << endl;
	int pos = 0, cnt = 0;
	for (int i = 0; i < n; i++) {
		if (f[i] >= i) 
			pos = i;
		else break;
	}
	for (int j = pos+1; j < n; j++)
		if (f[j] == pos)
			cnt++;
	// cerr << cnt << " " << f[pos]-pos << endl;
	if (!(cnt&1) && !((f[pos]-pos)&1)) puts("Second");
	else puts("First");
	return 0;
}
