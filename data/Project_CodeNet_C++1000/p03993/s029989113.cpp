#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	int n; cin >> n;
	vector<int> v(n + 1);
	rep(i, 1, n + 1) cin >> v[i];
	int cnt = 0;
	rep(i, 1, n + 1) if (v[v[i]] == i) cnt++;
	cout << cnt/2 << endl;
}

