#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;

int main()
{
	long long Q = 0, H = 0, S = 0, D = 0;
	long long N = 0;

	cin >> Q >> H >> S >> D;
	cin >> N;

	// 1L の最小値
	long long p1 = min(Q * 4, H * 2);
	p1 = min(p1, S);

	// 2L の最小値
	long long p2 = min(Q * 8, H * 4);
	p2 = min(p2, S * 2);
	p2 = min(p2, D);
		
	long long sum = 0;
	if (N % 2) {
		sum += p1;
	}

	long long num2 = N / 2;
	sum += num2 * p2;
		
	cout << sum << endl;

	return 0;
}