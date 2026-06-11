#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <functional>
#include <cmath>
#include <set>
#include <queue>
#include <deque>
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
	vector<int> p(N);
	for (auto i = 0; i < N; ++i)
	{
		cin >> p[i];
		--p[i];
	}

	vector<ll> a;
	vector<ll> b;
	for (auto i = 0; i < N; ++i)
	{
		a.push_back((ll)2 * N * i + 1);
		b.push_back((ll)2 * N * (N - i - 1) + 1);
	}

	for (auto i = 0; i < N; ++i)
	{
		b[p[i]] += i;
	}

	for (auto i = 0; i < N; ++i)
	{
		cout << a[i];
		if (i < N - 1)
		{
			cout << " ";
		}
	}
	cout << endl;
	for (auto i = 0; i < N; ++i)
	{
		cout << b[i];
		if (i < N - 1)
		{
			cout << " ";
		}
	}
	cout << endl;


	return 0;
}