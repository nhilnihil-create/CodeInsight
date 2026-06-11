#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int N, K;
	cin >> N >> K;
	vector<int> x(N);
	int ans = 0;
	for (int i = 0; i < N; i++) {
		cin >> x[i];
		ans += 2 * min(x[i], abs(x[i] - K));
	}
	cout << ans << endl;
	return 0;
}