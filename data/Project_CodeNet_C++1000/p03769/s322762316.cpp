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
	while (1) {
		M++;
		if (pow(2, M) - 1 > N) {
			M--;
			break;
		}
	}
	vector<int>ans(M * 2);
	for (int i = 0; i < M; i++) {
		ans[i] = i + 1;
		ans[i + M] = i + 1;
	}
	N -= pow(2, M) - 1;
	while (N) {
		K = 0;
		while (1) {
			K++;
			if (pow(2, K)  > N) {
				K--;
				break;
			}
		}
		ans.push_back(M + 1);
		ans.insert(ans.begin() + K, M + 1);
		N -= pow(2, K) ;
		M++;
	}
	cout << ans.size() << endl;
	for (auto i : ans) {
		cout << i << " ";
	}
	cout << endl;
	return 0;
}