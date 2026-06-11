#include <iostream>
#include <vector>
using namespace std;

const long long INF = 1LL << 60;

int main() {
	int N, M; cin >> N >> M;
	vector<int> a(M), b(M);
	vector<long long> c(M);

	for (int i = 0; i < M; i++) {
		cin >> a[i] >> b[i] >> c[i];
		c[i] = -c[i];
		a[i]--, b[i]--;
	}
	
	vector<long long> dist(N, INF);
	dist[0] = 0;
	for (int iter = 0; iter < N-1; iter++) {
		for (int i = 0; i < M; i++) {
			if (dist[a[i]] == INF) continue;
			if (dist[b[i]] > dist[a[i]] + c[i]) {
				dist[b[i]] = dist[a[i]] + c[i];
			}
		}
	}
	long long ans = dist[N-1];

	vector<bool> neg(N, false);
	for (int iter = 0; iter < N; iter++) {
		for (int i = 0; i < M; i++) {
			if (dist[a[i]] == INF) continue;
			if (dist[b[i]] > dist[a[i]] + c[i]) {
				dist[b[i]] = dist[a[i]] + c[i];
				neg[b[i]] = true;
			}
			if (neg[a[i]]) neg[b[i]] = true;
		}
	}

	if (neg[N-1])
		cout << "inf" << endl;
	else
		cout << -ans << endl;
}
