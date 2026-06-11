#include<iostream>
#include<string>
#include<vector>
#include<numeric>
#include<math.h>
#include<algorithm>
#include<iomanip>
#include<list>
#include<bitset>
using namespace std;

int main() {

	long long N, A, B;
	cin >> N >> A >> B;

	long long ans = (N - 2) * B - (N - 2) * A + 1;

	if (ans < 0) {
		cout << 0 << endl;
	}
	else {
		cout << ans << endl;
	}

	return 0;
}