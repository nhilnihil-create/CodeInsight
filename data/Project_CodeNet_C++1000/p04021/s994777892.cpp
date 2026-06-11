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
	vector<int> A(N), B;
	set<int> o, e;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	B = A;
	sort(B.begin(), B.end());
	for (int i = 0; i < N; i++) {
		if (i % 2 == 0)e.insert(B[i]);
		else o.insert(B[i]);
	}
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		if (i % 2 == 0) {
			if (e.count(A[i]) == 0)cnt++;
		}
		else {
			if (o.count(A[i]) == 0)cnt++;
		}
	}
	cout << cnt / 2 << endl;
}