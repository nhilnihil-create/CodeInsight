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
#include "cmath"

using namespace std;

const long long int MOD = 1000000007;

long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<int>v(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> v[i];
	}
	M = -1;
	K = -1;
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	for (int i = 0; i <= N; i++) {
		if (M==-1&&v[i] <= i) {
			M = i - 1;
		}
		if (K==-1&&M >= v[i]) {
			K = i;
		}
	}
	//cout << M << " " << K << endl;
	if ((v[M] - M) % 2 && (K - M) % 2) {
		cout << "Second\n";
	}
	else {
		cout << "First\n";
	}
	return 0;
}
