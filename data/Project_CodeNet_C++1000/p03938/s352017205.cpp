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
	int N;
	cin >> N;
	vector<int> A(N), B(N), p(N);
	for (int i = 0; i < N; i++) {
		cin >> p[i];
		p[i]--;
		A[i] = i + 1;
		B[i] = N - i;
	}
	for (int i = 0; i < N; i++) {
		for (int j = p[i]; j < N; j++) {
			A[j] += i;
		}
		for (int j = 0; j <= p[i]; j++) {
			B[j] += i;
		}
	}
	for (int i = 0; i < N; i++) {
		cout << A[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < N; i++) {
		cout << B[i] << " ";
	}
	cout << endl;
}