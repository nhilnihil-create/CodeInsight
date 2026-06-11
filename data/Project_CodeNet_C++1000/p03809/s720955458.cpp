#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(V) (V).begin(),(V).end()

vector<vector<ll>> T(100000);
vector<ll> A(100000);

bool j = false;
ll solve(int x, int y) {
	if (j)return 0;
	int ss = T[y].size();
	if (ss == 1)
		return A[y];
	ll cnt = 0, mcnt = 0, a;
	for (int i = 0;i < ss;i++) {
		if (T[y][i] == x)continue;
		a = solve(y, T[y][i]);
		cnt += a;
		mcnt = max(a, mcnt);
		if (j)break;
	}
	ll ans = A[y] * 2 - cnt;
	if (ans > cnt || ans < max(2 * mcnt - cnt, (ll)0))
		j = true;
	if (j)return 0;
	return ans;
}

int main() {
	ll N;
	cin >> N;
	for (int i = 0;i < N;i++) {
		cin >> A[i];
	}
	int a, b;
	for (int i = 0;i < N - 1;i++) {
		cin >> a >> b;
		a--; b--;
		T[a].push_back(b);
		T[b].push_back(a);
	}
	ll a1 = solve(a, b);
	ll a2 = solve(b, a);
	if (j) a1 = -512411;
	if (a1 == a2)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}