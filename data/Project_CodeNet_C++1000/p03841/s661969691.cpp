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
#include "random"

using namespace std;

const long long int MOD = 1000000007;
const long double EPS = 0.00000001;
const long double PI = 3.1415926535897932384626433;

long long int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<int>num(N + 1);
	vector<int>ans(N*N + 1);
	queue<int>mae;
	stack<int>ushiro;
	for (int i = 1; i <= N; i++) {
		cin >> num[i];
		ans[num[i]] = i;
	}
	for (int i = 1; i <= N*N; i++) {
		if (ans[i]) {
			for (int j = 1; j < ans[i]; j++) {
				mae.push(ans[i]);
			}
			for (int j = ans[i] ; j < N; j++) {
				ushiro.push(ans[i]);
			}
		}
	}
	for (int i = 1; i <= N*N; i++) {
		if (mae.empty())break;
		if (!ans[i]) {
			ans[i] = mae.front();
			mae.pop();
		}
	}
	for (int i = N*N; i >= 1; i--) {
		if (ushiro.empty())break;
		if (!ans[i]) {
			ans[i] = ushiro.top();
			ushiro.pop();
		}
	}
	for (int i = 1; i <= N; i++) {
		int order = 0;
		for (int j = 1; j <= num[i]; j++) {
			if (ans[j] == i) {
				order++;
			}
		}
		if (order != i) {
			cout << "No\n";
			return 0;
		}
	}
	cout << "Yes\n";
	for (int i = 1; i <= N*N; i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
	return 0;
}
