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
ll MOD = 1000000007; ll INF = 9999999999999; ll ans = 1;
vl flag, color, D; vll path;
//***********//
int main() {
	cin >> H >> W;
	vector<string> A(H);
	vl P(26);
	ll a = 'a';
	for (i = 0; i < H; i++) {
		cin >> A[i];
		for (j = 0; j < W; j++) {
			P[A[i][j] - a]++;
		}
	}
	ll one = 0;
	ll two = 0;
	ll four = 0;
	if (W % 2 == 1 && H % 2 == 1) {
		one = 1;
		two = W / 2 + H / 2;
		four = (W / 2) * (H / 2);
	}
	else if (W % 2 == 1 && H % 2 == 0) {
		two = H / 2;
		four = (W / 2) * (H / 2);
	}
	else if (W % 2 == 0 && H % 2 == 1) {
		two = W / 2;
		four = (W / 2) * (H / 2);
	}
	else {
		four = (W * H) / 4;
	}
	ll now = 0;
	ll noChange = 0;
	ll one2 = 0;
	ll two2 = 0;
	ll four2 = 0;
	while (true) {
		noChange ++;
		if (P[now]>0 && (P[now] % 4 == 1 || P[now] % 4 == 3)) {
			P[now]--; one2++; noChange = 0;
		}
		if (P[now]>0 && P[now] % 4 == 2) {
			P[now] -= 2; two2++; noChange = 0;
		}
		if (P[now]>0 && P[now] % 4 == 0) {
			P[now] -= 4; four2++; noChange = 0;
		}
		now = (now + 1) % 26;
		if (noChange > 10000) {
			break;
		}
	}
	//cout << one << " " << one2 << endl;
	//cout << two << " " << two2 << endl;
	//cout << four << " " << four2 << endl;
	for (i = 0; i < 26; i++) {
		if (P[i] != 0) ans = 0;
	}
	if (two2 > two) ans = 0;
	if (one2 > one) ans = 0;
	if (ans) cout  << "Yes";
	else cout << "No";
}