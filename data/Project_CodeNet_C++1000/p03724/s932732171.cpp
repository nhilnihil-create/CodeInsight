#include "bits/stdc++.h"
using namespace std;
int main() {
	long long N, M;
	cin >> N >> M;
	vector<pair<long long, long long>>A(M);
	vector<long long>Tree(N, 0);
	for (long long i = 0; i < M; i++) {
		cin >> A.at(i).first >> A.at(i).second;
		Tree.at(A.at(i).first - 1) += 1;
		Tree.at(A.at(i).second - 1) += -1;
	}
	if (M == 1) {
		cout << "NO" << endl;
		return 0;
	}
	long long ans = Tree.at(0);
	for (long long i = 1; i < N; i++) {
		ans += Tree.at(i);
		if (ans != 0 && ans % 2 != 0) { 
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;

}