#include"bits/stdc++.h"
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define PI 3.141592653589793238

int main() {
	int N;
	cin >> N;
	priority_queue<int> a;
	rep(i, 3*N) {
		int A;
		cin >> A;
		a.push(A);
	}
	int64_t ans = 0;
	rep(i, N) {
		a.pop();
		ans += a.top();
		a.pop();
	}
	cout << ans << endl;
	return 0;
}