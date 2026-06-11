#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;

typedef long long s64;

s64 n;

int cur;
deque<int> result;

void solve(s64 n)
{
	if (n == 1ll)
		cur = 0;
	else
	{
		solve(n / 2);
		result.push_back(++cur);

		if (n & 1)
			result.push_front(++cur);
	}
}

int main()
{
	cin >> n;

	solve(n + 1);

	for (int i = 1; i <= cur; ++i)
		result.push_back(i);

	cout << result.size() << endl;
	for (int i : result)
		cout << i << ' ';
	cout << endl;

	return 0;
}