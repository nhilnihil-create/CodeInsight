#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <deque>

using namespace std;

long long n;
int m;
deque<int> ans;

void solve(long long n)
{
	if(n <= 1) return ;
	if(n & 1)
		solve(n - 1), ans.push_front(++m);
	else
		solve(n / 2), ans.push_back(++m);
}

int main()
{
	ios::sync_with_stdio(false);
	// freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);

	cin >> n;
	m = 0;
	solve(n + 1);

	cout << 2 * m << endl;
	for(int i = 0; i < ans.size(); i++)
		cout << ans[i] << ' ';
	for(int i = 1; i <= m; i++)
		cout << i << ' ';

	return 0;
}
