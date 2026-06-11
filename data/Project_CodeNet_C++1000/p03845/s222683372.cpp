// #include <bits/stdc++.h>
#include<iostream>
#include<iomanip>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<set>
#include<map>
#include<queue>
#define rep(i,n) for(int i=0;i<n;i++)
#define exf(x)	 for(auto&& tmp : x) { cout << tmp << endl; }	// 拡張for
#define PI 3.14159265358979323846264338327950288
const int MOD{ int(1e9 + 7) };	// = 1000000007
const int inf{ 2100000000 };	// = 2100000000 (MAX:2147483647)
typedef long long ll;
using namespace std;

// -------------------------------------------------- //
// ------------------ ここから本編 ------------------ //
// -------------------------------------------------- //

int main(void) {

	int N; cin >> N;
	vector<int> T(N);
	int sum = 0;
	rep(i, N) {
		cin >> T[i];
		sum += T[i];
	}

	int M; cin >> M;
	vector<int> ans(M, sum);
	rep(i, M) {
		int p, x; cin >> p >> x;
		ans[i] -= T[p - 1] - x;
	}

	for (auto x : ans) cout << x << endl;
	return 0;
}
