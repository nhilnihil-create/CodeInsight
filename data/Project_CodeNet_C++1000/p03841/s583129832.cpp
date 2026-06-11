#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

using i64 = long long;
using pii = pair<int, int>;

const int N = 505, NN = N * N;

int f[N], p[N], v[NN];

vector<pii> srt;
int n;

static void check(bool p) {
	if (!p) {
		cout << "No" << endl;
		exit(0); } }

int main() {
#ifdef HOME
	freopen("agc8d.in", "r", stdin);
	freopen("agc8d.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int dr, st(1);

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> p[i];
		v[p[i]] = i;
		srt.emplace_back(p[i], i); }

	sort(begin(srt), end(srt));
	for (auto i: srt) {
		for (f[i.y] = 1; f[i.y] < i.y; ++f[i.y]) {
			while (v[st]) ++st;
			check(st <= i.x);
			v[st] = i.y; } }

	dr = n * n;
	reverse(begin(srt), end(srt));
	for (auto i: srt) {
		for (; f[i.y] < n; ++f[i.y]) {
			while (v[dr]) --dr;
			check(dr >= i.x);
			v[dr] = i.y; } }

	cout << "Yes\n";
	for (int i = 1; i <= n * n; ++i)
		cout << v[i] << " \n"[i == n * n];

	return 0; }
