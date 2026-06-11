#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const long long INF = 1LL << 60;

int main() {
	int N;
	cin >> N;
	vector<int> a(3*N);
	for (int i = 0; i < 3*N; i++) cin >> a[i];

	priority_queue<int, vector<int>, greater<int>> queue_l;
	vector<long long> sum_l(N+1);
	for (int i = 0; i < N; i++) {
		queue_l.push(a[i]);
		sum_l[0] += a[i];
	}
	for (int i = 0; i < N; i++) {
		queue_l.push(a[i+N]);
		sum_l[i+1] = sum_l[i] + a[i+N] - queue_l.top();
		queue_l.pop();
	}

	priority_queue<int, vector<int>> queue_r;
	vector<long long> sum_r(N+1);
	for (int i = 0; i < N; i++) {
		queue_r.push(a[i+2*N]);
		sum_r[N] += a[i+2*N];
	}
	for (int i = 0; i < N; i++) {
		queue_r.push(a[2*N-1-i]);
		sum_r[N-1-i] = sum_r[N-i] + a[2*N-1-i] - queue_r.top();
		queue_r.pop();
	}

	long long ans = -INF;
	for (int i = 0; i < N+1; i++) {
		ans = max(ans, sum_l[i] - sum_r[i]);
	}
	cout << ans << endl;
}