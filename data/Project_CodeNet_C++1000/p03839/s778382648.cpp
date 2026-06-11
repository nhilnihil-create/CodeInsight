#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<tuple>
#include<functional>

using namespace std;

typedef long long ll;
typedef tuple<int, int, int> T3;

struct task {
	int a, b;
	task(int x, int y) { a = x, b = y; }
	task() = default;
};

int n, r;
vector<task> pos;
vector<T3> neg;

int main() {
	int N, K;
	cin >> N >> K;
	vector<ll> a(N);
	for (int i = 0; i < N; i++)cin >> a[i];

	vector<ll> csum(N + 1), poscsum(N + 1);
	for (int i = 0; i < N; i++)
		csum[i + 1] = csum[i] + a[i], 
		poscsum[i + 1] = poscsum[i] + (a[i] >= 0 ? a[i] : 0);

	ll ans = 0;
	for (int i = 0; i <= N - K; i++) {
		ans = max(ans, poscsum[i] + (poscsum[N] - poscsum[i + K]) + 
			(csum[i + K] - csum[i] > 0 ? csum[i + K] - csum[i] : 0));
	}
	cout << ans << "\n";
	return 0;
}