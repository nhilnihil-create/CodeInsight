#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"

using namespace std;

const long long int MOD = 1000000007;

long long int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<long long int>v(N + 1);
	vector<string> s(N);
	cin >> v[0];
	s[0] = "+";
	for (int i = 1; i < N; i++) {
		cin >> s[i] >> v[i];
	}
	vector<long long int>sum = v;
	for (int i = N - 1; i >= 0; i--) {
		sum[i] += sum[i + 1];
	}

	vector<long long int>Mdp(N + 1, -MOD * MOD);
	vector<long long int>mdp(N + 1, MOD*MOD);
	Mdp[N] = 0;
	mdp[N] = 0;
	for (int i = N - 1; i >= 0; i--) {
		if (s[i] == "+") {
			Mdp[i] = Mdp[i + 1] + v[i];
			mdp[i] = mdp[i + 1] + v[i];
		}
		else {
			Mdp[i] = max(Mdp[i + 1] - v[i], -mdp[i + 1] - v[i]);
			mdp[i] = -sum[i];
		}
	}
	cout << Mdp[0] << endl;
	return 0;
}