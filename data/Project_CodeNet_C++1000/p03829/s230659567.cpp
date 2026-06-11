#include <iostream>
#include <vector>
using namespace std;

int main() {
	long long N, A, B;
	cin >> N >> A >> B;
	vector<long long> X(N);
	for (int i = 0; i < N; i++) cin >> X[i];
	long long ans = 0;
	for (int i = 1; i < N; i++) ans += min((X[i] - X[i-1])*A, B);
	cout << ans << endl;
}
