#include <bits/stdc++.h>
#define mod 1000000007
#define sp ' '
#define intmax 2147483647
#define llmax 9223372036854775807
#define mkp make_pair
typedef long long ll;
using namespace std;

int N, A[300][300];
bool b[300][300];
ll res;

int main() {
	cin >> N;
	for (int i = 0; i != N; ++i) {
		for (int j = 0; j != N; ++j) {
			cin >> A[i][j];
			b[i][j] = true;
		}
	}
	for (int i = 0; i != N; ++i) {
		for (int j = 0; j != N; ++j) {
			for (int k = 0; k != N; ++k) {
				if (i == j || j == k || k == i)continue;
				if (A[i][j] + A[j][k] < A[i][k]) {
					cout << -1 << endl;
					return 0;
				}
				if (A[i][j] + A[j][k] == A[i][k]) {
					b[i][k] = false;
				}
			}
		}
	}
	for (int i = 0; i != N; ++i) {
		for (int j = i + 1; j != N; ++j) {
			if (b[i][j])res += A[i][j];
		}
	}
	cout << res << endl;
	return 0;
}