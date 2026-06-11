#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int n; 
char s[maxn];
bool a[maxn], b[maxn];
void solve()
{
	for(int i = 3; i <= n; ++i)
		a[i] = b[i - 1] ^ a[i - 1] ^ a[i - 2];
	if(b[n] != (a[n - 1] ^ a[n] ^ a[1]))
		return;
	if(b[1] != (a[n] ^ a[1] ^ a[2]))
		return;
	for(int i = 1; i <= n; ++i)
		s[i] = a[i] ? 'W' : 'S';
	puts(s + 1);
	exit(0);
}
int main()
{
	scanf("%d%s", &n, s + 1);
	for(int i = 1; i <= n; ++i) 
		b[i] = s[i] == 'o' ? 0 : 1;
	solve();
	a[1] = 1;
	solve();
	a[2] = 1;
	solve();
	a[1] = 0;
	solve();
	puts("-1");
	return 0;
}
	