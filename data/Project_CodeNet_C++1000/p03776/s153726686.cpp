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
	int N, A, B;
	cin >> N >> A >> B;
	vector<ll> v(N);
	for (auto i = 0; i < N; ++i)
	{
		cin >> v[i];
	}

	sort(v.begin(), v.end(), greater<ll>());

	auto sum = 0ll;
	auto cur = 0ll;
	auto num = 0;
	auto numA = 0;
	for (auto i = 0; i < N; ++i)
	{
		if (i < A)
		{
			sum += v[i];
			if (cur != v[i])
			{
				cur = v[i];
				num = 0;
				numA = 0;
			}
			++num;
			++numA;
		}
		else if (cur == v[i])
		{
			++num;
		}
	}

	auto ave = (double)sum / A;
	auto maxNum = 0;
	if (v[A - 1] == v[0])
	{
		maxNum = min(B - A + numA, num);
	}
	else
	{
		maxNum = numA;
	}
	auto result = 0ll;
	auto comb = 1ll;
	for (auto i = 1; i <= maxNum; ++i)
	{
		comb *= num - i + 1;
		comb /= i;
		if (i >= numA)
		{
			result += comb;
		}
	}

	cout << fixed << setprecision(10) << ave << endl;
	cout << result << endl;

	return 0;
}