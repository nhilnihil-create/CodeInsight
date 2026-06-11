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
		mp[a]++;
	}

	int startI = mp.begin()->first;
	int endI = (--mp.end())->first;
	int maxCount = 0;
	for (int i = startI; i < endI + 1; ++i) {
		int count = mp[i] + mp[i - 1] + mp[i + 1];
		maxCount = max(count, maxCount);
	}

	cout << maxCount << endl;
	return 0;
}
