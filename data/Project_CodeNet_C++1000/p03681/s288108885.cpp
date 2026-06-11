#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <numeric>
#include <iterator>

using namespace std;

namespace {

}

int main()
{
	int N = 0, M = 0;

	cin >> N >> M;
	
	if (abs(N - M) >= 2) {
		cout << 0 << endl;
		return 0;
	}
	long long bigN = 1000000000LL + 7;
	long long num = 1;
	if (N == M) {

		for (long long i = 1; i <= N; ++i) {
			num = (num * i) % bigN;
		}
		num = 2 * ((num * num) % bigN) % bigN;

	}	
	else {
		long long minN = min(N, M);
		for (long long i = 1; i <= minN; ++i) {
			num = (num * i) % bigN;
		}
		num = (((num * num) % bigN) * max(N, M)) % bigN;
	}

	cout << num << endl;

	return 0;
}