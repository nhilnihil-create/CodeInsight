#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;

int main() {
	ll N, A, B; cin >> N >> A >> B;
	vector<ll>X(N); for (auto&& x : X)cin >> x;

	ll sum = 0;
	for (int i = 1; i < N; i++) {
		sum += min((X[i] - X[i - 1]) * A, B);
	}
	cout << sum << endl;

	return 0;
}