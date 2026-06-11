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
#include "iomanip"

using namespace std;

const long long int MOD = 1000000007;

long long int N, M, K, H, W, L, R;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	vector<int>num(N);
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	M = num[N - 1];
	K = 0;
	for (int i = N - 1; i >= 0; i--) {
		M = max((int)M, num[i]);
		K = max(K, M - num[i]);
		num[i] = M - num[i];
	}
	M = 0;
	for (int i = 0; i < N; i++) {
		if (num[i] == K)M++;
	}
	cout << M << endl;
	return 0;
}