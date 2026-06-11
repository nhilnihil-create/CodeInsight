#include <string>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <iostream>
#include <functional>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <cmath>
#include <limits>
#include <tuple>
#include <queue>
#include <stack>

using namespace std;
typedef long long ll;

int main()
{
	int N;
	cin >> N;
	vector<vector<int>> A(N, vector<int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> A[i][j];
		}
	}
	ll ans = 0;
	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			int tmp = numeric_limits<int>::max();
			for (int k = 0; k < N; k++) {
				if (k != i && k != j) {
					tmp = min(tmp, A[i][k] + A[k][j]);
				}
			}
			if (tmp < A[i][j]) {
				ans = -1;
				goto exit;
			}
			if (tmp > A[i][j])
				ans += A[i][j];
		}
	}
exit:
	cout << ans << endl;
	return 0;
}
