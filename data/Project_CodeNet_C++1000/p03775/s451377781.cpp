#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> R;

int digit(long long A) {
	
	int c = 0;

	while (A != 0) {
		c++;
		A /= 10;
	}

	return c;
}

long long divisor(long long N) {
	
	long long F;
	long long mincost = 1 << 24;

	for (long long a = 1; a*a <= N; a++){
		if (N%a != 0) continue;
	
		long long b = N / a;

		F = max(digit(a), digit(b));
	
		if (F < mincost)
			mincost = F;
	}

	return mincost;

}

int main(void) {
	long long N;
	cin >> N;

	long long res = divisor(N);

	cout << res;
}