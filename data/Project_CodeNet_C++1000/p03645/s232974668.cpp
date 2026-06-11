#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL -1
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	int N, M;
	cin >> N >> M;

	vector<vector<int>> v(N, vector<int>());
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		v.at(a - 1).push_back(b - 1);
		v.at(b - 1).push_back(a - 1);
	}

	//for (int i = 0; i < N; i++) {
	//	if (v.at(i).size() == 0) continue;
	//	else {
	//		for (int j = 0; j < v.at(i).size(); j++) {
	//			cout << v.at(i).at(j) << ' ';
	//		}
	//	}
	//	cout << endl;
	//}

	for (int i = 0; i < v.at(0).size(); i++) {
		int n = v.at(0).at(i);
		if (v.at(n).size() == 0) continue;

		for (int j = 0; j < v.at(n).size(); j++) {
			if (v.at(n).at(j) == N - 1) {
				cout << "POSSIBLE" << endl;
				return 0;
			}
		}
	}
	cout << "IMPOSSIBLE" << endl;
}