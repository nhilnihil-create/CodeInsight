#pragma region template
#include "bits/stdc++.h"
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD = 1e9 + 7, MAX = 1e18, larg = 1e5, INF = -1e18;
long long A, B, C, D, E, F, G, H, I, J, K, L, N, M, O, P, Q, R, S, T, U, V, W, x, y, z;
long long max_value = INF, max_index = -1;
long long min_value = MAX, min_index = -1;
typedef long long ll;
typedef pair<ll, ll> Pa;

int arr[100001];
int main() {
	cin >> N;
	int cnt = 0;
	rep(i, N + 1) {
		arr[i] = 0;
	}
	rep(i, N) {
		cin >> A;
		arr[i + 1] = A;
		if (arr[arr[i + 1]] == i + 1) {
			cnt++;
		}
	}
	cout << cnt;
}
