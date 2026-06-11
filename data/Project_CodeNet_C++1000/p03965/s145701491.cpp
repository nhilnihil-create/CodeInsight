#pragma region template
#include "bits/stdc++.h"
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD = 1e9+7, MAX = 1e18, larg = 1e5, INF = -1e18;
long long A, B, C, D, E, F, G, H, I, J, K, L, N, M, O, P, Q, R, S, T, U, V, W, x, y, z;
long long max_value = INF, max_index = -1;
long long min_value = MAX, min_index = -1;
typedef long long ll;

char func(char prev, char ox, char beast) {
	bool flag = true;
	if (prev == 'W') flag = !flag;
	if (ox == 'x') flag = !flag;
	if (beast == 'W') flag = !flag;
	if (flag) return 'S';
	else return 'W';
}

char tmp[100000];
int main() {
	string s;
	cin >> s;
	int g_cnt = 0, p_cnt = 0;
	rep(i, s.size()) {
		if (s[i] == 'g') g_cnt++;
		else p_cnt++;
	}
	int mg_cnt = (s.size() + 1) / 2, mp_cnt = s.size() / 2;
	cout << mp_cnt - p_cnt;
}
