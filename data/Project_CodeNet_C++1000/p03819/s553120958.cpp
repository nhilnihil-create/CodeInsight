#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(V) V.begin(),V.end()
#define MOD 1000000007

vector<int> seg(262144);
int imos[100010];
vector<int> X[100010];
map<int, int> Y[100010];

int rsq(vector<int>&V, int s, int t, int k = 1, int l = 0, int r = 131071) {
	if (t < l || r < s)return 0;
	if (s <= l && r <= t)return V[k];

	int lv = rsq(V, s, t, k * 2, l, (l + r) / 2);
	int rv = rsq(V, s, t, k * 2 + 1, (l + r) / 2 + 1, r);
	return lv + rv;
}

void upd(int x) {
	x += 131072;
	seg[x]++;
	while (x) {
		x /= 2;
		seg[x] = seg[x * 2] + seg[x * 2 + 1];
	}
	return;
}

int main() {
	for (int i = 0;i < 262144;i++)seg[i] = 0;
	for (int i = 0;i < 100010;i++)imos[i] = 0;
	int N, M, l, r, s, t;
	cin >> N >> M;
	for (int i = 0;i < N;i++) {
		cin >> l >> r;
		X[l].push_back(r);
		imos[l]++;imos[r + 1]--;
	}
	for (int i = 1;i <= M;i++) {
		imos[i] += imos[i - 1];
	}


	for (int i = 1;i <= M;i++) {
		for (int j : X[i]) {
			upd(j);
		}

		for (int j = 1;j * j <= i;j++) {
			if (i % j)continue;
			t = i / j;
			Y[i].insert({ i + j,rsq(seg, i + j,M) });
			if (j != t)Y[i].insert({ i + t,rsq(seg, i + t,M) });
		}
	}
	
	ll ans;
	for (int i = 1;i <= M;i++) {
		ans = imos[i];
		s = i;
		while (s + i <= M) {
			ans += imos[s + i] - Y[s][s + i];
			s += i;
		}
		cout << ans << endl;
	}
}