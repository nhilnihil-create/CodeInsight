#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb emplace_back
const int maxn = 1e5+10;
#define int ll
int n, a[maxn];
#define yn(i) ((i)?"First":"Second")
signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	for (int i = 1;i <= n;++i)
		cin >> a[i];
	sort(a+1, a+1+n, greater<int>());
	int x = 1;
	bool res = false;
	while (x < n && a[x+1] >= x+1)
		++x;
	res = (x + a[x] - 1) % 2 == 0;
	//cout << "X " << x << '\n';
	int y = x;
	while (y < n && a[y+1] >= x)
		++y;
	res |= (y + a[y] - 1) % 2 == 0;
	//cout << "X " << y << '\n';
	puts(yn(res));
}
