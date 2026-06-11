#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const double PI = 3.141592653589793238;
const double EPS = 1e-10;
ll x[100000];
int perm[100000];
bool used[100000];
ll d[100000];
int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> x[i];
	for (int i = 0; i + 1 < N; i++) perm[i] = i;
	int M;
	ll K;
	cin >> M >> K;
	for (int i = 0; i < M; i++) {
		int a;
		cin >> a;
		a--;
		swap(perm[a], perm[a - 1]);
	}
	for (int i = 0; i + 1 < N; i++) {
		if (used[i]) continue;
		vector<int> v;
		while (!used[i]) {
			v.push_back(i);
			used[i] = 1;
			i = perm[i];
		}
		for (int j = 0; j < v.size(); j++) {
			int k = v[(j + K) % v.size()];
			d[v[j]] = x[k + 1] - x[k];
		}
	}
	cout << x[0] << endl;
	ll now = x[0];
	for (int i = 0; i + 1 < N; i++) {
		now += d[i];
		cout << now << endl;
	}
}
