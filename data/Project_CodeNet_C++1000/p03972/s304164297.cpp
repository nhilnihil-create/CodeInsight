#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int w, h, p[N], q[N];
vector < pair<int, int> > vec;
long long res;
int cnt[2];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> w >> h;
	for (int i = 0; i < w; ++i) {
		cin >> p[i];
		vec.push_back(make_pair(p[i], 0));
	}
	for (int i = 0; i < h; ++i) {
		cin >> q[i];
		vec.push_back(make_pair(q[i], 1));
	}

	sort(vec.begin(), vec.end());
	cnt[0] = w + 1;
	cnt[1] = h + 1;

	for (auto e : vec) {
		int val = e.first;
		int t = e.second;
		res += 1LL * cnt[t ^ 1] * val;
		cnt[t]--;
	}

	cout << res << endl;
}