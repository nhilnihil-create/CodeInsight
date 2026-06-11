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
		if (3200 < a) a = 3200;
		mp[a / 400]++;
	}

	int ans = 0;
	for (int i = 0; i < 8; ++i) {
		if (mp[i] != 0) {
			++ans;
		}
	}
	int minAns = 0;
	int maxAns = 0;
	minAns = max(1, ans);
	maxAns = ans + mp[8];

	cout << minAns << " " << maxAns << endl;
	return 0;
}