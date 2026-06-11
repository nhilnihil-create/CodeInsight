#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++) cin >> A[i];
	sort(A.begin(), A.end());
	long long sum = 0;
	int ans = 0;
	for (int i = 0; i < N; i++) {
		if (sum * 2 >= A[i]) {
			ans++;
			sum += A[i];
		}
		else {
			ans = 1;
			sum += A[i];
		}
	}
	cout << ans << endl;
}