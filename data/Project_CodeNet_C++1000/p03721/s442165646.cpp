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
	long long K;
	cin >> N >> K;

	map<int, long long> mp;
	for (int i = 0; i < N; ++i) {
		int a, b;
		cin >> a >> b;

		mp[a] += b;
	}
	
	long long count = 0;
	for (auto x : mp) {
		count += x.second;
		if (K <= count) {
			cout << x.first << endl;
			return 0;
		}
	}

	return 0;
}