#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 10;
typedef long long ll;
int a[maxn];
int n;
ll ans;
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= 3 * n; ++i) scanf("%d", &a[i]);
	sort(a + 1, a + 3 * n + 1); 
	for(int i = n + 1; i <= 3 * n; i += 2) ans += a[i];
	cout << ans << endl;
	return 0;
}