#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

long long N, A[309][309];

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) cin >> A[i][j];
	}
	long long sum = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) {
			int cnt = 0;
			for (int k = 1; k <= N; k++) {
				if (i == k || j == k) continue;
				if (A[i][k] + A[k][j] < A[i][j]) { cout << "-1" << endl; return 0; }
				if (A[i][k] + A[k][j] == A[i][j]) cnt++;
			}
			if (cnt == 0) sum += A[i][j];
		}
	}
	cout << sum << endl;
	return 0;
}