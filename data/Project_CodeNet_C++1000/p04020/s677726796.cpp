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
	vector<ll> A(N);
	for (auto i = 0; i < N; ++i)
	{
		cin >> A[i];
	}

	auto sum = 0ll;
	for (auto i = 0; i < N; ++i)
	{
		sum += A[i] / 2;
		if (A[i] % 2 > 0
			&& i < N - 1
			&& A[i + 1] > 0)
		{
			++sum;
			--A[i + 1];
		}
	}

	cout << sum << endl;

	return 0;
}