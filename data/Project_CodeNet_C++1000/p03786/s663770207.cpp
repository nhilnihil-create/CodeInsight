#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <functional>
#include <cmath>
#include <set>
#include <queue>
#include <vector>
#include <climits>
#include <sstream>
#include <iomanip>
#include <map>
#include <stack>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;

int main()
{
	int N;
	cin >> N;
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
	for (auto i = 0; i < N; ++i)
	{
		ll A;
		cin >> A;
		q.push({ A, 1 });
	}

	while (q.size() > 1)
	{
		auto p = q.top();
		q.pop();
		auto p2 = q.top();
		q.pop();
		if (p.first * 2 >= p2.first)
		{
			q.push({ p.first + p2.first, p.second + p2.second });
		}
		else
		{
			q.push({ p.first + p2.first, p2.second });
		}
	}

	cout << q.top().second << endl;

	return 0;
}