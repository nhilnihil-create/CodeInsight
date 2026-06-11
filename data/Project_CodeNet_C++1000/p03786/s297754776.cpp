#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void solve() {
	int n;
	cin >> n;
	vector<ll> v(n);
	rep(i,n) cin >> v[i];
	sort(ALL(v));
	ll sum = 0;
	int i = 0;
	int cur = 0;
	while(i < n) {
		cur = i;
		sum += v[i];
		while (i < n - 1 && v[i + 1] <= sum * 2) {
			sum += v[i + 1];
			i++;
		}
		i++;
	}
	cout << max(0, n - cur) << endl;
}

int main() {
	solve();
	return 0;
}