#pragma GCC optimize("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target ("avx")
#define io_init cin.tie(0);ios::sync_with_stdio(0);cout<<setprecision(10)
#include <bits/stdc++.h>
constexpr int INF = 2147483647;
constexpr long long int INF_LL = 9223372036854775807;
constexpr int MOD = 1000000007;
constexpr double PI = 3.14159265358979323846;
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

int main() {
	io_init;
	int N, x;
	cin >> N >> x;
	if (N == 2) {
		if (x == 1 || x == 3) {
			cout << "No" << endl;
		}
		else {
			cout << "Yes" << endl;
			cout << 1 << endl << 2 << endl << 3 << endl;
		}
		return 0;
	}
	if (x <= 1 || x >= N * 2 - 1) {
		cout << "No" << endl;
		return 0;
	}
	vector<int> ans(2 * N - 1, -1), used(2 * N, 0);
	if (x == 2) {
		ans[N - 1] = 1;
		ans[N - 2] = x;
		ans[N - 3] = x + 1;
		ans[N] = x + 2;
		used[x] = used[1] = used[x + 1] = used[x + 2] = 1;
	}
	else {
		ans[N - 1] = x+1;
		ans[N - 2] = x;
		ans[N - 3] = 1;
		ans[N] = 2;
		used[x] = used[x + 1] = used[1] = used[2] = 1;
	}
	for (int i = 0, j = 1; i < ans.size(); i++) {
		if (ans[i] == -1) {
			while (used[j])j++;
			ans[i] = j;
			used[j] = 1;
		}
	}
	cout << "Yes" << endl;
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << endl;
	}
}