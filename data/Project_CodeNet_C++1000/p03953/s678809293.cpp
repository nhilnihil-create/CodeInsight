
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <functional>
#include <iomanip>
#include <bitset>
using namespace std;

typedef long long ll;



int N;
double x[100005], dx[100005];
ll M, K;
int a[100005];

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> x[i];
	cin >> M >> K;
	for (int i = 0; i < M; i++) cin >> a[i], a[i]--;

	for (int i = 0; i < N - 1; i++) dx[i] = x[i + 1] - x[i];
	vector<int> m(N - 1), m_(N - 1), ans(N - 1);
	for (int i = 0; i < N - 1; i++) m[i] = ans[i] = i;
	for (int i = 0; i < M; i++) swap(m[a[i] - 1], m[a[i]]);
	for (ll i = 0; (1LL << i) <= K; i++) {
		if ((K >> i) & 1) {
			for (int j = 0; j < N - 1; j++) ans[j] = m[ans[j]];
		}
		for (int j = 0; j < N - 1; j++) m_[j] = m[m[j]];
		swap(m_, m);
	}
	double pos = x[0];
	for (int i = 0; i < N; i++) {
		printf("%.10f\n", pos);
		if (i < N - 1) pos += dx[ans[i]];
	}
	return 0;
}