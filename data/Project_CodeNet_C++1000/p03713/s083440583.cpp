#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<cmath>
#include<list>
#include<set>
#include<map>

using namespace std;
long long MOD = 1000000007LL;
const double PI = 3.14159265358979323846;
#undef INT_MIN
#undef INT_MAX
#define INT_MIN -2147483648
#define INT_MAX 2147483647
#define endl "\n"

int main() {
	long long H, W;
	cin >> H >> W;

	if (H % 3 == 0 || W % 3 == 0) {
		cout << 0 << endl;
		return 0;
	}

	long long buf1 = W;
	long long buf2 = H;
	long long ans = INT_MAX;
	{
		long long areaMax;
		long long areaMin;
		buf1 = max(H, W);
		buf2 = min(H, W);
		if (0 < (int)ceil(buf1 / 3.0)) {
			areaMax = max({ buf2 * ceil(buf1 / 3.0), buf2 * floor(buf1 / 3.0) });
			areaMin = min({ buf2 * ceil(buf1 / 3.0), buf2 * floor(buf1 / 3.0) });
			ans = areaMax - areaMin;
		}

		buf1 = min(H, W);
		buf2 = max(H, W);
		if (0 < (int)ceil(buf1 / 3.0)) {
			areaMax = max({ buf2 * ceil(buf1 / 3.0), buf2 * floor(buf1 / 3.0) });
			areaMin = min({ buf2 * ceil(buf1 / 3.0), buf2 * floor(buf1 / 3.0) });
			ans = min(ans, areaMax - areaMin);
		}
	}
	{
		buf1 = H;
		buf2 = W;
		for (long long i = 1; i <= buf1; ++i) {
			long long areaMax = max({ i * buf2, (buf1 - i) * (int)ceil(buf2 / 2.0), (buf1 - i) * (int)floor(buf2 / 2.0) });
			long long areaMin = min({ i * buf2, (buf1 - i) * (int)ceil(buf2 / 2.0), (buf1 - i) * (int)floor(buf2 / 2.0) });

			if (areaMax < areaMin) {
				continue;
			}

			ans = min(ans, areaMax - areaMin);
		}
	}
	{
		buf1 = W;
		buf2 = H;
		for (long long i = 1; i <= buf1; ++i) {
			long long areaMax = max({ i * buf2, (buf1 - i) * (int)ceil(buf2 / 2.0), (buf1 - i) * (int)floor(buf2 / 2.0) });
			long long areaMin = min({ i * buf2, (buf1 - i) * (int)ceil(buf2 / 2.0), (buf1 - i) * (int)floor(buf2 / 2.0) });

			if (areaMax < areaMin) {
				continue;
			}

			ans = min(ans, areaMax - areaMin);
		}
	}




	cout << ans << endl;
	return 0;
}