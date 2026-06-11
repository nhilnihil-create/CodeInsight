#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;
using LLONG = long long;
const LLONG MOD = 1000000007;

int main()
{
	int N, M, K; cin >> N >> M >> K;
	// O(NM) <= O(1e6)
	for (int r = 0; r <= N; ++r)
	{
		for (int c = 0; c <= M; ++c)
		{
			int blackNum = r * (M - c) + (N - r) * c;
			if (blackNum == K)
			{
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	cout << "No" << endl;
}