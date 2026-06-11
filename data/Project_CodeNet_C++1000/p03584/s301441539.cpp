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

int main()
{
	int N, K;
	cin >> N >> K;

	vector<int> A(N);
	vector<long long> B(N);
	for (auto i = 0; i < N; ++i)
	{
		cin >> A[i] >> B[i];
	}

	auto result = 0ll;
	auto mask = 0x7FFFFFFF;
	for (auto i = 32; i >= 0; --i)
	{
		auto bit = 0;
		if (i > 0)
		{
			bit = (1 << (i - 1));
			if ((K & bit) == 0)
			{
				mask = mask >> 1;
				continue;
			}
		}

		auto temp = K & (~bit);
		temp = ~(temp | mask);
		auto sum = 0ll;
		for (auto j = 0; j < N; ++j)
		{
			if ((A[j] & temp) == 0)
			{
				sum += B[j];
			}
		}
		result = max(result, sum);
		mask = mask >> 1;
	}

	cout << result << endl;

	return 0;
}