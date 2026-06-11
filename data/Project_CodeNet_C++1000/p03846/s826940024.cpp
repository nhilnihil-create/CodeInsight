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
	int N;
	cin >> N;
	
	map<int, int> mp;

	for (int i = 0; i < N; ++i) {
		int a;
		cin >> a;
		++mp[a];
	}

	bool flags = true;
	int i = 0;
	if (N % 2 == 0) {
		i = 1;
	}
	else {
		if (mp[0] != 1) {
			cout << 0 << endl;
			return 0;
		}
		i = 2;
	}
	for (; i < N; i += 2) {
		if (mp[i] != 2) {
			cout << 0 << endl;
			return 0;
		}
	}


	long long ans = 1;
	for (int i = 0; i < N / 2; ++i) {
		ans = (ans * 2) % MOD;
	}

	cout << ans << endl;
	return 0;
}