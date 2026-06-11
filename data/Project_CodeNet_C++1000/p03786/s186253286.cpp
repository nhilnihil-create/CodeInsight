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
	sort(A.begin(), A.end());

	auto num = 1;
	auto sum = 0ll;
	for (auto i = 0; i < N - 1; ++i)
	{
		sum += A[i];
		if (sum * 2 >= A[i + 1])
		{
			++num;
		}
		else
		{
			num = 1;
		}
	}

	cout << num << endl;

	return 0;
}