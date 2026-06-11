#include<iostream>
#include<algorithm>
#include<vector>
#include<deque>

using namespace std;

typedef long long ll;

int N;
ll X;
vector<ll> a;
vector<ll> cost[2000 + 10];

vector<ll> Slide_minimum(const vector<ll>& ar, int k) {
	//k=1の時は普通にa[i]を参照する。
	int n = ar.size();
	vector<ll> ret;
	deque<ll> deq;
	for (int i = 0; i < n; i++) {
		while (deq.size() && ar[deq.back()] > ar[i])deq.pop_back();
		deq.push_back(i);
		if (k <= i + 1) {
			ret.push_back(ar[deq.front()]);
			if(deq.front() == i - k + 1)deq.pop_front();
		}
	}
	return ret;
}

int main() {
	cin >> N >> X;
	a.resize(2 * N);
	for (int i = 0; i < N; i++)cin >> a[i], a[i + N] = a[i];

	for (int k = 0; k < N; k++) {
		cost[k] = Slide_minimum(a, k + 1);
	}

	ll ans = 1145141919810893;
	for (int k = 0; k < N; k++) {
		ll spend = k * X;
		for (int i = 0; i < N; i++) {
			spend += cost[k][(N + i - k) % N];
		}
		ans = min(ans, spend);
	}
	cout << ans << endl;
	return 0;
}