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
	int N, M;
	cin >> N >> M;
	vector<pair<long long, long long>> a;
	vector<pair<long long, long long>> b;

	for (int i = 0; i < N; ++i) {
		long long x, y;
		cin >> x >> y;
		a.push_back(make_pair(x, y));
	}
	for (int i = 0; i < M; ++i) {
		long long x, y;
		cin >> x >> y;
		b.push_back(make_pair(x, y));
	}
	

	for (int i = 0; i < N; ++i) {
		long long minMan = INT_MAX;
		int _j = 0;
		for (int j = 0; j < M; ++j) {
			long long man = abs(a[i].first - b[j].first) + abs(a[i].second - b[j].second);
			if (man < minMan) {
				_j = j + 1;
				minMan = man;
			}
		}
		cout << _j << endl;
	}
	return 0;
}