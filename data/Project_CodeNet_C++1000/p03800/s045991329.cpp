#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <string.h>
using namespace std; using ll = long long; using pll = pair<ll, ll>;
using vl = vector<ll>; using vll = vector<vl>; using vpll = vector<pll>;
int ctoi(char c) {
	switch (c) {
	case '0': return 0; case '1': return 1; case '2': return 2;
	case '3': return 3; case '4': return 4; case '5': return 5;
	case '6': return 6; case '7': return 7; case '8': return 8;
	case '9': return 9;  default: return 0;
	}
}
bool pairCompare(const pll firstElof, pll secondElof)
{
	return firstElof.first > secondElof.first;
}
//**Snippetリスト**//
//rep, vin, all, iteLoop//
//gcdlcm, isPrime, eratos, divisor, modinv, bitSearch, bitList, dfs, bfs//
//dijkstra, UnionFind, COM, digitDP//
ll i, j, k, l; ll N, M, K, H, W, L;
ll MOD = 1000000007; ll INF = 9999999999999; ll ans = -1;
vl flag, color, D; vll path;
//***********//
int main() {
	cin >> N;
	string S;
	cin >> S;
	//N,1タイ目の組み合わせで決める
	vl Ans(N);
	vl T(N);
	for (i = 0; i < N; i++) {
		if (S[i] == 'o') T[i] = 0;
		else T[i] = 1;
	}
	for (l = 0; l < 4; l++) {
		ll k = l;
		Ans[0] = k % 2; k /= 2; Ans[1] = k % 2;
		for (i = 0; i <= N - 3; i++) {
			if (Ans[i] == 0) Ans[i + 2] = Ans[i + 1] ^ T[i + 1];
			else Ans[i + 2] = !(Ans[i + 1] ^ T[i + 1]);
		}
		ll pre0 = 0; ll pre1 = 0;
		if (Ans[N - 2] == 0) pre0 = Ans[N - 1] ^ T[N - 1];
		else pre0 = !(Ans[N - 1] ^ T[N - 1]);
		if (Ans[N - 1] == 0) pre1 = pre0 ^ T[0];
		else pre1 = !(pre0 ^ T[0]);
		//for (j = 0; j < N; j++) {
			//cout << Ans[j];
		//}
		//cout << endl << pre0 << pre1 << endl;
		if (Ans[0] == pre0 && Ans[1] == pre1) {
			for (i = 0; i < N; i++) {
				if (Ans[i])cout << "W";
				else cout << "S";
			}
			exit(0);
		}
	}
	cout << -1;
}