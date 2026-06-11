#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int a[maxn];
bool gao(const int &l, const int &r, const int &t)
{
	if(l == r)
		return ~(a[l] - t) & 1;
	int len = r - l + 1;
	for(int i = l; i < r; i ++)
		if(a[i] != t + 1)
			return gao(i, r - 1, t + 1);
	return (~len & 1) || (~(a[r] - t) & 1);
}
int main()
{
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	cout << (gao(1, n, 0) ? "First" : "Second") << endl;
	
	return 0;
}