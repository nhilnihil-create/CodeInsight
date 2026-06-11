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
	map<long long, int> mp;
	for (int i = 0; i < N; ++i) {
		int a;
		cin >> a;
		mp[a]++;
	}

	int count = 0;
	for (auto x : mp) {
		if (x.second % 2 == 1)++count;
	}

	cout << count << endl;
	return 0;
}