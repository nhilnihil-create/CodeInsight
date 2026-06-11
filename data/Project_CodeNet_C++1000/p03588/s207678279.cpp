#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL -1
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	int N;
	cin >> N;

	vector<pair<int64_t, int64_t>> v;
	for (int i = 0; i < N; i++) {
		pair<int64_t, int64_t> p;
		cin >> p.first >> p.second;
		v.push_back(p);
	}
	sort(v.begin(), v.end());

	//for (int i = 0; i < N; i++) {
	//	cout << v.at(i).first << ' ' << v.at(i).second << endl;
	//}

	int64_t sum = 0;
	sum += v.at(0).first - 1;
	sum += v.at(N - 1).second;
	sum += v.at(N - 1).first - v.at(0).first + 1;

	cout << sum << endl;
}
