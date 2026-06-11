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

	int N, M; cin >> N >> M;
	char A[51][51];
	char B[51][51];
	rep(y, N) rep(x, N) cin >> A[y][x];
	rep(y, M) rep(x, M) cin >> B[y][x];

	bool ok = false;
	rep(y, N) rep(x, N) {
		bool flag = true;
		rep(j, M) rep(i, M) {
			if (j >= N || i >= N) {
				flag = false;
				j = i = M;
			}
			if (A[y + j][x + i] != B[j][i]) {
				flag = false;
				j = i = M;
			}
		}
		ok = flag ? true : false;
		if (ok) y = x = N;
	}
	cout << (ok ? "Yes" : "No") << endl;
	return 0;
}
