#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <queue>
#include <cmath>

using namespace std;
using ll = long long;
using ull = unsigned long long;

ll Combination(int n, int r)
{
	std::vector<std::vector<ll> > v(n + 1, std::vector<ll>(n + 1, 0));
	for (size_t i = 0; i < v.size(); i++) {
		v[i][0] = 1;
		v[i][i] = 1;
	}
	for (size_t j = 1; j < v.size(); j++) {
		for (size_t k = 1; k < j; k++) {
			v[j][k] = (v[j - 1][k - 1] + v[j - 1][k]);
		}
	}
	return v[n][r];
}

void ABC057D()
{
	int N, A, B;
	cin >> N >> A >> B;
	vector<ll> v(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end(), greater<ll>());

	ll sum = 0;
	for (int i = 0; i < A; ++i)
	{
		sum += v[i];
	}
	double avg = static_cast<double>(sum) / A;
	cout << std::fixed << std::setprecision(30) << avg << endl;

	ll ct = 0;
	if (v[A - 1] == v[0])
	{
		int n = A;
		for (int i = A; i < N; ++i)
		{
			if (v[i] == v[0])
			{
				++n;
			}
		}
		int C = min(B, n);
		for (int i = A; i <= C; ++i)
		{
			ct += Combination(n, i);
		}
		cout << ct << endl;
		return;
	}

	int k1 = 0;
	for (int i = A; i < N; ++i)
	{
		if (v[i] == v[A - 1])
		{
			++k1;
		}
	}
	int k2 = 0;
	for (int i = A - 1; i > -1; --i)
	{
		if (v[i] == v[A - 1])
		{
			++k2;
		}
	}
	int k = k1 + k2;
	ct = Combination(k, k2);
	cout << ct << endl;

}
int main()
{
	ABC057D();
	return 0;
}