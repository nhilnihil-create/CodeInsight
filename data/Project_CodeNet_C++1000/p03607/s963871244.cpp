#include<iostream>
#include<string>
#include<vector>
#include<numeric>
#include<math.h>
#include<algorithm>
#include<iomanip>
#include<list>
#include<bitset>
using namespace std;

int main() {

	int N;
	cin >> N;

	vector<int> A(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	sort(A.begin(), A.end());

	A.push_back(0);

	int ans = 0;
	int cnt = 1;

	for (int i = 0; i < N; i++) {
		if (A[i] == A[i + 1]) {
			cnt += 1;
		}
		else {
			if (cnt % 2 != 0) {
				ans += 1;
			}
			cnt = 1;
		}
	}

	cout << ans << endl;


	return 0;
}