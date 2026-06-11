
// D - 3N Numbers

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

ll a[300000];
ll left_max[200001]; // 左からi個目までからN個選ぶ時の総和の最大値
ll right_min[200001]; // 右からi個目までからN個選ぶ時の総和の最小値

int main() {
	int N;
	cin >> N;

	for (int i=0; i<3*N; i++) {
		cin >> a[i];
	}

	// 左からi個目までからN個選ぶ時の総和の最大値を計算
	priority_queue<ll, vector<ll>, greater<ll>> lpq;
	for (int i=1; i<=N; i++) {
		int j = i - 1;
		left_max[N] += a[j];
		lpq.push(a[j]);
	}

	//cout << "i=" << N << " " << left_max[N] << endl; // **** debug ****

	for (int i=N+1; i<=2*N; i++) {
		int j = i - 1;
		if (a[i-1] > lpq.top()) {
			left_max[i] = left_max[i-1] - lpq.top() + a[j];
			lpq.pop();
			lpq.push(a[j]);
		} else {
			left_max[i] = left_max[i-1];
		}

		//cout << "i=" << i << " " << left_max[i] << endl; // **** debug ****
	}

	// 右からi個目までからN個選ぶ時の総和の最小値を計算
	priority_queue<ll> rpq;
	for (int i=1; i<=N; i++) {
		int j = 3*N - i;
		right_min[N] += a[j];
		rpq.push(a[j]);
	}

	//cout << "i=" << N << " " << right_min[N] << endl; // **** debug ****

	for (int i=N+1; i<=2*N; i++) {
		int j = 3*N - i;
		if (a[j] < rpq.top()) {
			right_min[i] = right_min[i-1] - rpq.top() + a[j];
			rpq.pop();
			rpq.push(a[j]);
		} else {
			right_min[i] = right_min[i-1];
		}

		//cout << "i=" << i << " " << right_min[i] << endl; // **** debug ****
	}

	ll ans = -INF;

	for (int i=N; i<=2*N; i++) {
		ans = max(ans, left_max[i] - right_min[3*N - i]);
	}

	cout << ans << endl;

	return 0;
}